CON_3_out = "{\"morpheme id\":\"2\",\"word\":\"11\",\"stem\":\"11\",\"gcat\":\"CON\"}";
CON_5_out = "{\"morpheme id\":\"3\",\"word\":\"22\",\"stem\":\"22\",\"gcat\":\"CON\"}";
CON_7_out = "{\"morpheme id\":\"4\",\"word\":\"33\",\"stem\":\"33\",\"gcat\":\"CON\"}";
CALLENGV_1_1_morphology = "{\"morpheme id\":\"1\",\"word\":\"call\",\"stem\":\"call\",\"gcat\":\"V\",\"tags\":[\"call[stem]\",\"V\"]}";

function CALLENGV_1_1(functionName, parameterList, CON_3_out, CON_5_out, CON_7_out, CALLENGV_1_1_morphology) {
    contact = "";
    for (i = 0; i < parameterList.length; ++i) {
        if (parameterList[i].indexOf('CON_') > -1) {
            if (typeof arguments[i + 2] !== 'undefined' && arguments[i + 2].length > 0) {
                con = JSON.parse(arguments[i + 2]);
                if (contact.length > 0) contact = contact + " " + con.stem;
                else contact = con.stem;
            }
        } else if (parameterList[i].indexOf('Noun_') > -1) {
            if (typeof arguments[i + 2] !== 'undefined' && arguments[i + 2].length > 0) {
                con = JSON.parse(arguments[i + 2]);
                if (contact.length > 0) contact = contact + " " + con.stem;
                else contact = con.stem;
            }
        } else if (parameterList[i].indexOf('Num_') > -1) {
            if (typeof arguments[i + 2] !== 'undefined' && arguments[i + 2].length > 0) {
                contact += arguments[i + 2];
            }
        } else if (parameterList[i].indexOf('FIRSTLASTENGN_') > -1) {
            if (typeof arguments[i + 2] !== 'undefined' && arguments[i + 2].length > 0) {
                contact += arguments[i + 2];
            }
        }
    }
    console.log(contact);
};
CALLENGV_1_1_out = CALLENGV_1_1('CALLENGV_1_1', ['CON_3_out', 'CON_5_out', 'CON_7_out', 'CALLENGV_1_1_morphology'], CON_3_out, CON_5_out, CON_7_out, CALLENGV_1_1_morphology);