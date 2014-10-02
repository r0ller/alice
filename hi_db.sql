create table LEXICON(
word varchar(256),
gcat varchar(12),
lexeme varchar(32),
PRIMARY KEY(word, gcat)
);

create table ENTITIES(
entity varchar(32) primary key references LEXICON(lexeme),
is_a varchar(32) references LEXICON(lexeme),
options varchar(512)
);

/*
To be able to handle different meanings of modifiers, the options field
should be moved to a different table with a scheme (<property,entity>,options),
where property and entity are the keys and property references lexeme in Lexicon,
while entity references entity in Entities:

create table PROPERTIES(
property varchar(32) references LEXICON(lexeme),
entity varchar(32) references ENTITIES(entity),
options varchar(512)
PRIMARY KEY(property, entity)
);

This would solve the problem posed by phrases: 'long files'<>'long directories',
where long needs to be interpreted in a different way.
Similarly, to handle different meanings for adverbs when introduced, there
should be a table like:

create table ADVERBS(
adverb varchar(32) references LEXICON(lexeme),
relation varchar(32) references RELATIONS(relation),
options varchar(512)
PRIMARY KEY(adverb, relation)
);
*/

create table RELATIONS(
relation varchar(32) references LEXICON(lexeme),
preposition varchar(32) references LEXICON(lexeme),
argument varchar(32) references ENTITIES(entity),
command varchar(512),
PRIMARY KEY(relation, preposition, argument)
);

insert into LEXICON values('list', 'V', 'LIST');
insert into LEXICON values('copy', 'V', 'COPY');
insert into LEXICON values('directory', 'N', 'DIRECTORY');
insert into LEXICON values('directories', 'N', 'DIRECTORY');
insert into LEXICON values('executable', 'A', 'EXECUTABLE');
insert into LEXICON values('non-executable', 'A', 'NON-EXECUTABLE');
insert into LEXICON values('all', 'QPro', 'ALL');
insert into LEXICON values('file', 'N', 'FILE');
insert into LEXICON values('files', 'N', 'FILE');
insert into LEXICON values('to', 'Prep', 'TO');
insert into LEXICON values('remove', 'V', 'REMOVE');
insert into LEXICON values('delete', 'V', 'DELETE');
insert into LEXICON values('from', 'Prep', 'FROM');
insert into LEXICON values('change', 'V', 'CHANGE');
insert into LEXICON values('move', 'V', 'MOVE');
insert into LEXICON values('in', 'Prep', 'IN');
insert into LEXICON values('make', 'V', 'MAKE');

insert into ENTITIES values('FILE', 'FILE', 'tests=''-type f'';');
insert into ENTITIES values('EXECUTABLE', 'FILE', 'tests=''-type f -perm /111'';');
insert into ENTITIES values('NON-EXECUTABLE', 'FILE', 'tests=''! -perm /111'';');
insert into ENTITIES values('DIRECTORY', 'NON-EXECUTABLE', 'tests=''-type d'';');

insert into RELATIONS values('LIST', '', '', 'target=/dev/stdout;options=''-maxdepth 1'';find $source$delim$constant $options -fprint $target;constant=;');
insert into RELATIONS values('LIST', '', 'DIRECTORY', 'target=/dev/stdout;export source;export delim;export constant;export tests;export options=''-maxdepth 1'';export target;echo -e ''if [ -z $constant ]\nthen\nfind $source$delim$constant $options $tests -fprint $target\nelse\nfind $source$delim$constant $options -fprint $target\nfi'' 1>command;chmod a+x command;./command;constant=;');
insert into RELATIONS values('LIST', '', 'FILE', 'target=/dev/stdout;options=''-maxdepth 1'';find $source$delim$constant $options $tests -fprint $target;constant=;');
insert into RELATIONS values('COPY', '', '', 'cp -f $source$delim$constant $target;constant=;');
insert into RELATIONS values('COPY', '', 'FILE', 'export source;export delim;export constant;export tests;export options=''-maxdepth 1'';export target;echo -e ''files="$(find $source$delim$constant $options $tests)";\nfor f in $files\ndo\ncp -f $f $target\ndone'' 1>command;chmod a+x command;./command;constant=;');
insert into RELATIONS values('COPY', '', 'DIRECTORY', 'cp -f $source$delim$constant/* $target;constant=;');
insert into RELATIONS values('REMOVE', '', '', 'rm $source$delim$constant;constant=;');
insert into RELATIONS values('REMOVE', '', 'DIRECTORY', 'rmdir $source$delim$constant;constant=;');
insert into RELATIONS values('REMOVE', '', 'FILE', 'find $source$delim$constant $options $tests -exec rm ''{}'' +;constant=;');
insert into RELATIONS values('DELETE', '', '', 'rm $source$delim$constant;constant=;');
insert into RELATIONS values('DELETE', '', 'DIRECTORY', 'rmdir $source$delim$constant;constant=;');
insert into RELATIONS values('DELETE', '', 'FILE', 'find $source$delim$constant $options $tests -exec rm ''{}'' +;constant=;');
insert into RELATIONS values('CHANGE', '', 'DIRECTORY', 'cd $target;constant=;');
insert into RELATIONS values('MAKE', '', 'DIRECTORY', 'mkdir $target$delim$constant;constant=;');
insert into RELATIONS values('MOVE', '', '', 'mv -f $source$delim$constant $target;constant=;');
insert into RELATIONS values('MOVE', '', 'DIRECTORY', 'mv -f $source$delim$constant/* $target;constant=;');
insert into RELATIONS values('MOVE', '', 'FILE', 'export source;export delim;export constant;export tests;export options=''-maxdepth 1'';export target;echo -e ''files="$(find $source$delim$constant $options $tests)";\nfor f in $files\ndo\nmv -f $f $target\ndone'' 1>command;chmod a+x command;./command;constant=;');
insert into RELATIONS values('LIST', 'TO', 'FILE', 'target=/dev/stdout;');
insert into RELATIONS values('LIST', 'IN', 'DIRECTORY', 'source=.;delim=/;');
insert into RELATIONS values('COPY', 'FROM', 'DIRECTORY', 'source=.;delim=/;');
insert into RELATIONS values('COPY', 'TO', 'DIRECTORY', 'target=.;');
insert into RELATIONS values('REMOVE', 'FROM', 'DIRECTORY', 'source=.;delim=/;');
insert into RELATIONS values('DELETE', 'FROM', 'DIRECTORY', 'source=.;delim=/;');
insert into RELATIONS values('CHANGE', 'TO', 'DIRECTORY', 'target=~;');
insert into RELATIONS values('MOVE', 'FROM', 'DIRECTORY', 'source=.;delim=/;');
insert into RELATIONS values('MOVE', 'TO', 'DIRECTORY', 'target=.;');
insert into RELATIONS values('MAKE', 'IN', 'DIRECTORY', 'target=.;delim=/;');
