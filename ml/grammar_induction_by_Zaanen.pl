#!/usr/pkg/bin/perl -w
use strict;
use vars qw($opt_h $opt_i $opt_o $opt_l $opt_d);
use Getopt::Std;

$opt_i ="-"; # default value
$opt_o ="-"; # default value
getopts('hi:o:ld');

$opt_h ||=0; # default value
$opt_d ||=0; # default value
$opt_l ||=0; # default value

my $usage =
  "Usage: $0 [OPTION]\.\.\.
This program converts an ABL file into a Nuance GSL file\.

  -i FILE   Name of input file (default: $opt_i)
  -o FILE   Name of output file (default: $opt_o)
  -l        Convert left recurive rules to right recursive (default: off)
  -d        Debug (default: off)
  -h        Show this help and exit
";

die $usage if $opt_h;

die $usage if $opt_i eq "";
open(INPUT, "<$opt_i")
  || die "Couldn't open input file: $!\n";

die $usage if $opt_o eq "";
open(OUTPUT, ">$opt_o")
  || die "Couldn't open outputfile: $!\n";


my %grammar;
my $start_nonterm;
my %first;

sub read_line() {
  my $line=<INPUT>;
  while (defined($line) and ($line=~/^#/)) {
    $line=<INPUT>;
  }
  return $line;
}

sub extract_structure {
  my $structure=$_[0];
  my %structure;
  my $constituent;
  while ($structure=~/\(\s*(\d+)\s*,\s*(\d+)\s*,\s*\[([^\]]+)\]\s*\)\s*/g) {
    my $b=$1;
    my $e=$2;
    my $n=$3;
    if ($n!~/^\d+$/) {
      die "Incorrect nonterminal format: $n";
    }
    if ($b!=$e) {
      $structure{$b}{$e}=$n;
    }
  }
  return %structure;
}

sub find_rhs {
  my @sentence=@{$_[0]};
  my %structure=%{$_[1]};
  my $begin=$_[2];
  my $end=$_[3];
  my @result;
  my $counter=$begin;
  while ($counter!=$end) {
    if (defined($structure{$counter})) {
      # handle non-term
      my @keys=sort { $a < $b } keys %{$structure{$counter}};
      if ($keys[0]>$end) {
        die "Found overlapping constituent: ($counter,$keys[0],[${$structure{$counter}}{$keys[0]}])";
      }
      my $nonterm=translate_nonterm(${$structure{$counter}}{$keys[0]});
      push (@result, $nonterm);
      find_grammar(\@sentence, \%structure, $counter, $keys[0]);
      $counter=$keys[0];
    }
    else {
      # handle term
      push (@result, $sentence[$counter]);
      ++$counter;
    }
  }
  return join(" ", @result);
}

sub find_grammar {
  my @sentence=@{$_[0]};
  my %structure=%{$_[1]};
  my $begin=$_[2];
  my $end=$_[3];
  my $top_level=$_[4];
  my $lhs="";
  if (defined($structure{$begin}) and
      defined(${$structure{$begin}}{$end})) {
    $lhs=${$structure{$begin}}{$end};
    delete ${$structure{$begin}}{$end};
    if (scalar(keys %{$structure{$begin}})==0) {
      delete $structure{$begin};
    }
  }
  if ($lhs eq "") {
    die "missing start symbol";
  }
  my $rhs=find_rhs(\@sentence, \%structure, $begin, $end);
  $lhs=translate_nonterm($lhs);
  if ($top_level) {
    $start_nonterm=$lhs;
  }
  ${$grammar{$lhs}}{$rhs}++;
}

sub translate_nonterm {
  my $in=$_[0];
  if ($in==0) {
    return "A";
  }
  my $result;
  while ($in!=0) {
    my $digit=$in%10;
    $in=($in-($in%10))/10;
    $result.=chr(ord("A")+$digit);
  }
  return $result;
}

sub remove_direct_left_recursion {
  my $Ai=$_[0];
  my @rhss=keys %{$grammar{$Ai}};
  my %recursive;
  my %nonrecursive;
  foreach my $rhs (@rhss) {
    if ($rhs=~/^$Ai\s*(.*)$/) {
      my $alpha=$1;
      $recursive{$alpha}++;
    }
    else {
      $nonrecursive{$rhs}++;
    }
  }
  if (scalar(keys %recursive)>0) {
    delete $grammar{$Ai}; # remove
    delete $first{$Ai};
    foreach my $rhs (keys %nonrecursive) {
      if ($rhs=~/^([A-Z]+)\s*(.*)$/) {
        $first{$Ai}{$1}=1;
      }
      $grammar{$Ai}{$rhs}++;
      $grammar{$Ai}{$rhs." $Ai'"}++;
    }
    foreach my $rest (keys %recursive) {
      if ($rest=~/^([A-Z]+)\s*(.*)$/) {
        $first{$Ai}{$1}=1;
      }
      $grammar{"$Ai'"}{$rest}++;
      $grammar{"$Ai'"}{$rest." $Ai'"}++;
    }
  }
}

sub remove_left_recursion {
  my $nonterm=$_[0];
print "handling $nonterm\n";
  if (defined($first{$nonterm})) { # already done
    print "already done\n";
    return;
  }
  # find left nonterms in first
  my @rhs=keys %{$grammar{$nonterm}};
  foreach my $rhs (@rhs) {
    if ($rhs=~/^([A-Z]+)\s*.*$/) {
      my $left_nonterm=$1;
      $first{$nonterm}{$left_nonterm}=1;
    }
  }
  print "first level:".join(" ", (keys %{$first{$nonterm}}))."\n";

  # find first of nonterms in first
  foreach my $left_nonterm (keys %{$first{$nonterm}}) {
    remove_left_recursion($left_nonterm);
    foreach my $n (keys %{$first{$left_nonterm}}) {
      $first{$nonterm}{$n}=1;
    }
  }
  if (defined($first{$nonterm}{$nonterm})) {
    my @chain=keys %{$first{$nonterm}};
    foreach my $a (keys %first) {
      print "$a:".join(" ", (keys %{$first{$a}}))."\n";
    }
    print "Identified chain $nonterm=".join(" ", @chain)."\n";
    remove_left_recursion_chain(\@chain);
    @chain=keys %{$first{$nonterm}};
    foreach my $a (keys %first) {
      print "$a:".join(" ", (keys %{$first{$a}}))."\n";
    }
    print "rest of chain: $nonterm=".join(" ", @chain)."\n";
  }
}

sub remove_left_recursion_chain {
  my @lhs=@{$_[0]};
  my $nr_lhs=scalar(@lhs)-1;
  for my $i (0 .. $nr_lhs) {
    my $Ai=$lhs[$i];
    my @rhs_Ai=keys %{$grammar{$Ai}};
    if ($opt_d) {
      print STDERR "Removing recursion of $Ai: ";
      print STDERR "$i of $nr_lhs (".scalar(@rhs_Ai).")\n";
    }
    for my $j (0 .. $i-1) {
      my $Aj=$lhs[$j];
      foreach my $rhs (@rhs_Ai) {
        if ($rhs=~/^$Aj\s*(.*)$/) {
          my $alpha=$1;
          delete ${$grammar{$Ai}}{$rhs};
          foreach my $beta (keys %{$grammar{$Aj}}) {
            ${$grammar{$Ai}}{"$beta $alpha"}++;
            if ($rhs=~/^([A-Z]+)\s*(.*)$/) {
              $first{$Ai}{$1}=1;
            }
          }
          delete $first{$Ai}{$Aj};
        }
      }
    }
    # transform direct left recursion
    remove_direct_left_recursion($Ai);
  }
}

sub remove_unreachable_rules {
  my %used_tokens;
  $used_tokens{$start_nonterm}++; # start is always reachable
  foreach my $lhs (keys %grammar) {
    foreach my $rhs (keys %{$grammar{$lhs}}) {
      foreach my $token (split(/\s+/, $rhs)) {
        $used_tokens{$token}++;
      }
    }
  }
  my @lhss=keys %grammar;
  foreach my $lhs (@lhss) {
    if (!defined($used_tokens{$lhs})) {
      delete $grammar{$lhs};
    }
  }
}

sub print_grammar {
  foreach my $lhs (sort keys %grammar) {
    my %rhss=%{$grammar{$lhs}};
    my @rhss;
    foreach my $rhs (keys %rhss) {
      if ($rhs=~/\s/) {
        push (@rhss, "($rhs)");
      }
      else {
        push (@rhss, "$rhs");
      }
    }
    if ($lhs eq $start_nonterm) {
      $lhs=".$lhs";
    }
    if (scalar(@rhss)>1) {
      print OUTPUT "$lhs [".join(" ", @rhss)."]\n";
    }
    else {
      print OUTPUT "$lhs ".join(" ", @rhss)."\n";
    }
  }
}

my $nr_lines;
my $line=read_line();
while (defined($line)) {
  $nr_lines++;
  chomp ($line);
  if ($line!~/^(.*)@@@(.*)$/) {
    die "Incorrect input: $line";
  }
  my @sentence=split(/\s+/, $1);
  my $structure=$2;
  my %structure=extract_structure($structure);
  # do top level
  find_grammar(\@sentence, \%structure, 0, scalar(@sentence), 1);
  $line=read_line();
}
if ($opt_d) {
  print STDERR "$nr_lines lines\n";
  print STDERR scalar(keys %grammar)." nonterminals\n";
  my $nr_rules;
  foreach my $nonterm (keys %grammar) {
    $nr_rules+=scalar(keys %{$grammar{$nonterm}});
  }
  print STDERR "$nr_rules rules\n";
}

if ($opt_l) {
  remove_left_recursion($start_nonterm);
#  remove_left_recursion();
#  remove_unreachable_rules();
  if ($opt_d) {
    print STDERR scalar(keys %grammar)." non left recursive nonterminals\n";
    my $nr_rules;
    foreach my $nonterm (keys %grammar) {
      $nr_rules+=scalar(keys %{$grammar{$nonterm}});
    }
    print STDERR "$nr_rules non left recursive rules\n";
  }
}
print_grammar();

close(INPUT);
close(OUTPUT);