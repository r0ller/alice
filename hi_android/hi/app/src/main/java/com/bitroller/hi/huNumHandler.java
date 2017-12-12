package com.bitroller.hi;

import java.util.ArrayList;

public class huNumHandler {
    private String number;
    private String text;
    private String suffix;

    public static ArrayList<huNumHandler> getNumbers(String text){
        String number="";
        String suffix="";
        boolean expectSuffix=false;

        ArrayList<huNumHandler> handlers=new ArrayList<huNumHandler>();
        for(int i=0;i<text.length();++i){
            if(Character.isSpaceChar(text.charAt(i))==true&&number.isEmpty()==false&&suffix.isEmpty()==false){
                handlers.add(new huNumHandler(number,suffix));
                suffix="";
                number="";
            }
            else if(Character.isSpaceChar(text.charAt(i))==true&&number.isEmpty()==false&&suffix.isEmpty()==true){
                expectSuffix=true;
            }
            else if(Character.isLetter(text.charAt(i))==true&&number.isEmpty()==false){
                suffix+=text.charAt(i);
            }
            else if(Character.isDigit(text.charAt(i))==true){
                if(expectSuffix==false) number+=text.charAt(i);
                else{
                    handlers.add(new huNumHandler(number,""));
                    suffix="";
                    number="";
                    number+=text.charAt(i);
                    expectSuffix=false;
                }
            }
        }
        if(number.isEmpty()==false) handlers.add(new huNumHandler(number,suffix));
    return handlers;
    }

    private huNumHandler(String number, String suffix){
        this.number=number;
        this.suffix=suffix;
        this.text="";

        String no0LeadingNumber="";
        for(int i=0;i<number.length();++i){
            if(number.charAt(i) == '0'&&no0LeadingNumber.isEmpty()==true) {
                text += " nulla ";
            }
            else{
                no0LeadingNumber+=number.charAt(i);
            }
        }
        if(no0LeadingNumber.length()<5) {//TODO: support longer numbers
            for (int i = 0; i < no0LeadingNumber.length(); ++i) {
                if (no0LeadingNumber.length() - i == 4) {
                    if (no0LeadingNumber.charAt(i) != '0' && no0LeadingNumber.charAt(i) != '1')
                        text += convertDigit(no0LeadingNumber.charAt(i)) + "ezer";
                    else if (no0LeadingNumber.charAt(i) == '1') text += "ezer";
                } else if (no0LeadingNumber.length() - i == 3) {
                    if (no0LeadingNumber.charAt(i) != '0' && no0LeadingNumber.charAt(i) != '1')
                        text += convertDigit(no0LeadingNumber.charAt(i)) + "száz";
                    else if (no0LeadingNumber.charAt(i) == '1') text += "száz";
                } else if (no0LeadingNumber.length() - i == 2) {
                    if (no0LeadingNumber.charAt(i + 1) == '0') {
                        text += convertDecimalNulled(no0LeadingNumber.charAt(i));
                    } else {
                        text += convertDecimalNotNulled(no0LeadingNumber.charAt(i));
                    }
                } else if (no0LeadingNumber.length() - i == 1) {
                    if (no0LeadingNumber.length() > 1 && no0LeadingNumber.charAt(i) != '0' || no0LeadingNumber.length() == 1)
                        text += convertDigit(no0LeadingNumber.charAt(i));
                }
            }
            if (suffix.contentEquals("t") == true || suffix.contentEquals("ot") == true || suffix.contentEquals("et") == true || suffix.contentEquals("at") == true || suffix.contentEquals("öt") == true) {
                if (no0LeadingNumber.endsWith("3") == true)
                    text = text.substring(0, text.lastIndexOf("három")) + "hárm";
                text += suffix;
            }
        }
        else this.text=number;
    }

    private String convertDigit(char digit){
        if (digit == '0') {
            return "nulla";
        } else if (digit == '1') {
            return "egy";
        } else if (digit == '2') {
            return "kettő";
        } else if (digit == '3') {
            return "három";
        } else if (digit == '4') {
            return "négy";
        } else if (digit == '5') {
            return "öt";
        } else if (digit == '6') {
            return "hat";
        } else if (digit == '7') {
            return "hét";
        } else if (digit == '8') {
            return "nyolc";
        } else if (digit == '9') {
            return "kilenc";
        }
        else return "";
    }

    private String convertDecimalNulled(char digit){
        if (digit == '1') {
            return "tíz";
        } else if (digit == '2') {
            return "húsz";
        } else if (digit == '3') {
            return "harminc";
        } else if (digit == '4') {
            return "negyven";
        } else if (digit == '5') {
            return "ötven";
        } else if (digit == '6') {
            return "hatvan";
        } else if (digit == '7') {
            return "hetven";
        } else if (digit == '8') {
            return "nyolcvan";
        } else if (digit == '9') {
            return "kilencven";
        }
        else return "";
    }

    private String convertDecimalNotNulled(char digit){
        if (digit == '1') {
            return "tizen";
        } else if (digit == '2') {
            return "huszon";
        } else if (digit == '3') {
            return "harminc";
        } else if (digit == '4') {
            return "negyven";
        } else if (digit == '5') {
            return "ötven";
        } else if (digit == '6') {
            return "hatvan";
        } else if (digit == '7') {
            return "hetven";
        } else if (digit == '8') {
            return "nyolcvan";
        } else if (digit == '9') {
            return "kilencven";
        }
        else return "";
    }

    public String numText(){
        return text;
    }

    public String suffix(){
        return suffix;
    }

    public String number(){
        return number;
    }

}
