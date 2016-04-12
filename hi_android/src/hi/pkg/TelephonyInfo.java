package hi.pkg;
//source: http://stackoverflow.com/questions/14517338/android-check-whether-the-phone-is-dual-sim
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import android.content.Context;
import android.support.v4.util.Pair;
import android.telephony.TelephonyManager;

public final class TelephonyInfo {

    private static TelephonyInfo telephonyInfo;
    private TelephonyManager telephonyManager;
    private String imsiSIM1;
    private String imsiSIM2;
    private boolean isSIM1Ready;
    private boolean isSIM2Ready;
    private static List<Pair<String, String>> countryCodes = new ArrayList<Pair<String, String>>();
    static
    {
    	countryCodes.add(new Pair<String,String>("AF","93"));
    	countryCodes.add(new Pair<String,String>("AL","355"));
    	countryCodes.add(new Pair<String,String>("DZ","213"));
    	countryCodes.add(new Pair<String,String>("AS","1-684"));
    	countryCodes.add(new Pair<String,String>("AD","376"));
    	countryCodes.add(new Pair<String,String>("AO","244"));
    	countryCodes.add(new Pair<String,String>("AI","1-264"));
    	countryCodes.add(new Pair<String,String>("AQ","672"));
    	countryCodes.add(new Pair<String,String>("AG","1-268"));
    	countryCodes.add(new Pair<String,String>("AR","54"));
    	countryCodes.add(new Pair<String,String>("AM","374"));
    	countryCodes.add(new Pair<String,String>("AW","297"));
    	countryCodes.add(new Pair<String,String>("AU","61"));
    	countryCodes.add(new Pair<String,String>("AT","43"));
    	countryCodes.add(new Pair<String,String>("AZ","994"));
    	countryCodes.add(new Pair<String,String>("BS","1-242"));
    	countryCodes.add(new Pair<String,String>("BH","973"));
    	countryCodes.add(new Pair<String,String>("BD","880"));
    	countryCodes.add(new Pair<String,String>("BB","1-246"));
    	countryCodes.add(new Pair<String,String>("BY","375"));
    	countryCodes.add(new Pair<String,String>("BE","32"));
    	countryCodes.add(new Pair<String,String>("BZ","501"));
    	countryCodes.add(new Pair<String,String>("BJ","229"));
    	countryCodes.add(new Pair<String,String>("BM","1-441"));
    	countryCodes.add(new Pair<String,String>("BT","975"));
    	countryCodes.add(new Pair<String,String>("BO","591"));
    	countryCodes.add(new Pair<String,String>("BA","387"));
    	countryCodes.add(new Pair<String,String>("BW","267"));
    	countryCodes.add(new Pair<String,String>("BR","55"));
    	countryCodes.add(new Pair<String,String>("IO","246"));
    	countryCodes.add(new Pair<String,String>("VG","1-284"));
    	countryCodes.add(new Pair<String,String>("BN","673"));
    	countryCodes.add(new Pair<String,String>("BG","359"));
    	countryCodes.add(new Pair<String,String>("BF","226"));
    	countryCodes.add(new Pair<String,String>("BI","257"));
    	countryCodes.add(new Pair<String,String>("KH","855"));
    	countryCodes.add(new Pair<String,String>("CM","237"));
    	countryCodes.add(new Pair<String,String>("CA","1"));
    	countryCodes.add(new Pair<String,String>("CV","238"));
    	countryCodes.add(new Pair<String,String>("KY","1-345"));
    	countryCodes.add(new Pair<String,String>("CF","236"));
    	countryCodes.add(new Pair<String,String>("TD","235"));
    	countryCodes.add(new Pair<String,String>("CL","56"));
    	countryCodes.add(new Pair<String,String>("CN","86"));
    	countryCodes.add(new Pair<String,String>("CX","61"));
    	countryCodes.add(new Pair<String,String>("CC","61"));
    	countryCodes.add(new Pair<String,String>("CO","57"));
    	countryCodes.add(new Pair<String,String>("KM","269"));
    	countryCodes.add(new Pair<String,String>("CK","682"));
    	countryCodes.add(new Pair<String,String>("CR","506"));
    	countryCodes.add(new Pair<String,String>("HR","385"));
    	countryCodes.add(new Pair<String,String>("CU","53"));
    	countryCodes.add(new Pair<String,String>("CW","599"));
    	countryCodes.add(new Pair<String,String>("CY","357"));
    	countryCodes.add(new Pair<String,String>("CZ","420"));
    	countryCodes.add(new Pair<String,String>("CD","243"));
    	countryCodes.add(new Pair<String,String>("DK","45"));
    	countryCodes.add(new Pair<String,String>("DJ","253"));
    	countryCodes.add(new Pair<String,String>("DM","1-767"));
    	countryCodes.add(new Pair<String,String>("DO","1-809"));
    	countryCodes.add(new Pair<String,String>("DO","1-829"));
    	countryCodes.add(new Pair<String,String>("DO","1-849"));
    	countryCodes.add(new Pair<String,String>("TL","670"));
    	countryCodes.add(new Pair<String,String>("EC","593"));
    	countryCodes.add(new Pair<String,String>("EG","20"));
    	countryCodes.add(new Pair<String,String>("SV","503"));
    	countryCodes.add(new Pair<String,String>("GQ","240"));
    	countryCodes.add(new Pair<String,String>("ER","291"));
    	countryCodes.add(new Pair<String,String>("EE","372"));
    	countryCodes.add(new Pair<String,String>("ET","251"));
    	countryCodes.add(new Pair<String,String>("FK","500"));
    	countryCodes.add(new Pair<String,String>("FO","298"));
    	countryCodes.add(new Pair<String,String>("FJ","679"));
    	countryCodes.add(new Pair<String,String>("FI","358"));
    	countryCodes.add(new Pair<String,String>("FR","33"));
    	countryCodes.add(new Pair<String,String>("PF","689"));
    	countryCodes.add(new Pair<String,String>("GA","241"));
    	countryCodes.add(new Pair<String,String>("GM","220"));
    	countryCodes.add(new Pair<String,String>("GE","995"));
    	countryCodes.add(new Pair<String,String>("DE","49"));
    	countryCodes.add(new Pair<String,String>("GH","233"));
    	countryCodes.add(new Pair<String,String>("GI","350"));
    	countryCodes.add(new Pair<String,String>("GR","30"));
    	countryCodes.add(new Pair<String,String>("GL","299"));
    	countryCodes.add(new Pair<String,String>("GD","1-473"));
    	countryCodes.add(new Pair<String,String>("GU","1-671"));
    	countryCodes.add(new Pair<String,String>("GT","502"));
    	countryCodes.add(new Pair<String,String>("GG","44-1481"));
    	countryCodes.add(new Pair<String,String>("GN","224"));
    	countryCodes.add(new Pair<String,String>("GW","245"));
    	countryCodes.add(new Pair<String,String>("GY","592"));
    	countryCodes.add(new Pair<String,String>("HT","509"));
    	countryCodes.add(new Pair<String,String>("HN","504"));
    	countryCodes.add(new Pair<String,String>("HK","852"));
    	countryCodes.add(new Pair<String,String>("HU","36"));
    	countryCodes.add(new Pair<String,String>("IS","354"));
    	countryCodes.add(new Pair<String,String>("IN","91"));
    	countryCodes.add(new Pair<String,String>("ID","62"));
    	countryCodes.add(new Pair<String,String>("IR","98"));
    	countryCodes.add(new Pair<String,String>("IQ","964"));
    	countryCodes.add(new Pair<String,String>("IE","353"));
    	countryCodes.add(new Pair<String,String>("IM","44-1624"));
    	countryCodes.add(new Pair<String,String>("IL","972"));
    	countryCodes.add(new Pair<String,String>("IT","39"));
    	countryCodes.add(new Pair<String,String>("CI","225"));
    	countryCodes.add(new Pair<String,String>("JM","1-876"));
    	countryCodes.add(new Pair<String,String>("JP","81"));
    	countryCodes.add(new Pair<String,String>("JE","44-1534"));
    	countryCodes.add(new Pair<String,String>("JO","962"));
    	countryCodes.add(new Pair<String,String>("KZ","7"));
    	countryCodes.add(new Pair<String,String>("KE","254"));
    	countryCodes.add(new Pair<String,String>("KI","686"));
    	countryCodes.add(new Pair<String,String>("XK","383"));
    	countryCodes.add(new Pair<String,String>("KW","965"));
    	countryCodes.add(new Pair<String,String>("KG","996"));
    	countryCodes.add(new Pair<String,String>("LA","856"));
    	countryCodes.add(new Pair<String,String>("LV","371"));
    	countryCodes.add(new Pair<String,String>("LB","961"));
    	countryCodes.add(new Pair<String,String>("LS","266"));
    	countryCodes.add(new Pair<String,String>("LR","231"));
    	countryCodes.add(new Pair<String,String>("LY","218"));
    	countryCodes.add(new Pair<String,String>("LI","423"));
    	countryCodes.add(new Pair<String,String>("LT","370"));
    	countryCodes.add(new Pair<String,String>("LU","352"));
    	countryCodes.add(new Pair<String,String>("MO","853"));
    	countryCodes.add(new Pair<String,String>("MK","389"));
    	countryCodes.add(new Pair<String,String>("MG","261"));
    	countryCodes.add(new Pair<String,String>("MW","265"));
    	countryCodes.add(new Pair<String,String>("MY","60"));
    	countryCodes.add(new Pair<String,String>("MV","960"));
    	countryCodes.add(new Pair<String,String>("ML","223"));
    	countryCodes.add(new Pair<String,String>("MT","356"));
    	countryCodes.add(new Pair<String,String>("MH","692"));
    	countryCodes.add(new Pair<String,String>("MR","222"));
    	countryCodes.add(new Pair<String,String>("MU","230"));
    	countryCodes.add(new Pair<String,String>("YT","262"));
    	countryCodes.add(new Pair<String,String>("MX","52"));
    	countryCodes.add(new Pair<String,String>("FM","691"));
    	countryCodes.add(new Pair<String,String>("MD","373"));
    	countryCodes.add(new Pair<String,String>("MC","377"));
    	countryCodes.add(new Pair<String,String>("MN","976"));
    	countryCodes.add(new Pair<String,String>("ME","382"));
    	countryCodes.add(new Pair<String,String>("MS","1-664"));
    	countryCodes.add(new Pair<String,String>("MA","212"));
    	countryCodes.add(new Pair<String,String>("MZ","258"));
    	countryCodes.add(new Pair<String,String>("MM","95"));
    	countryCodes.add(new Pair<String,String>("NA","264"));
    	countryCodes.add(new Pair<String,String>("NR","674"));
    	countryCodes.add(new Pair<String,String>("NP","977"));
    	countryCodes.add(new Pair<String,String>("NL","31"));
    	countryCodes.add(new Pair<String,String>("AN","599"));
    	countryCodes.add(new Pair<String,String>("NC","687"));
    	countryCodes.add(new Pair<String,String>("NZ","64"));
    	countryCodes.add(new Pair<String,String>("NI","505"));
    	countryCodes.add(new Pair<String,String>("NE","227"));
    	countryCodes.add(new Pair<String,String>("NG","234"));
    	countryCodes.add(new Pair<String,String>("NU","683"));
    	countryCodes.add(new Pair<String,String>("KP","850"));
    	countryCodes.add(new Pair<String,String>("MP","1-670"));
    	countryCodes.add(new Pair<String,String>("NO","47"));
    	countryCodes.add(new Pair<String,String>("OM","968"));
    	countryCodes.add(new Pair<String,String>("PK","92"));
    	countryCodes.add(new Pair<String,String>("PW","680"));
    	countryCodes.add(new Pair<String,String>("PS","970"));
    	countryCodes.add(new Pair<String,String>("PA","507"));
    	countryCodes.add(new Pair<String,String>("PG","675"));
    	countryCodes.add(new Pair<String,String>("PY","595"));
    	countryCodes.add(new Pair<String,String>("PE","51"));
    	countryCodes.add(new Pair<String,String>("PH","63"));
    	countryCodes.add(new Pair<String,String>("PN","64"));
    	countryCodes.add(new Pair<String,String>("PL","48"));
    	countryCodes.add(new Pair<String,String>("PT","351"));
    	countryCodes.add(new Pair<String,String>("PR","1-787"));
    	countryCodes.add(new Pair<String,String>("PR","1-939"));
    	countryCodes.add(new Pair<String,String>("QA","974"));
    	countryCodes.add(new Pair<String,String>("CG","242"));
    	countryCodes.add(new Pair<String,String>("RE","262"));
    	countryCodes.add(new Pair<String,String>("RO","40"));
    	countryCodes.add(new Pair<String,String>("RU","7"));
    	countryCodes.add(new Pair<String,String>("RW","250"));
    	countryCodes.add(new Pair<String,String>("BL","590"));
    	countryCodes.add(new Pair<String,String>("SH","290"));
    	countryCodes.add(new Pair<String,String>("KN","1-869"));
    	countryCodes.add(new Pair<String,String>("LC","1-758"));
    	countryCodes.add(new Pair<String,String>("MF","590"));
    	countryCodes.add(new Pair<String,String>("PM","508"));
    	countryCodes.add(new Pair<String,String>("VC","1-784"));
    	countryCodes.add(new Pair<String,String>("WS","685"));
    	countryCodes.add(new Pair<String,String>("SM","378"));
    	countryCodes.add(new Pair<String,String>("ST","239"));
    	countryCodes.add(new Pair<String,String>("SA","966"));
    	countryCodes.add(new Pair<String,String>("SN","221"));
    	countryCodes.add(new Pair<String,String>("RS","381"));
    	countryCodes.add(new Pair<String,String>("SC","248"));
    	countryCodes.add(new Pair<String,String>("SL","232"));
    	countryCodes.add(new Pair<String,String>("SG","65"));
    	countryCodes.add(new Pair<String,String>("SX","1-721"));
    	countryCodes.add(new Pair<String,String>("SK","421"));
    	countryCodes.add(new Pair<String,String>("SI","386"));
    	countryCodes.add(new Pair<String,String>("SB","677"));
    	countryCodes.add(new Pair<String,String>("SO","252"));
    	countryCodes.add(new Pair<String,String>("ZA","27"));
    	countryCodes.add(new Pair<String,String>("KR","82"));
    	countryCodes.add(new Pair<String,String>("SS","211"));
    	countryCodes.add(new Pair<String,String>("ES","34"));
    	countryCodes.add(new Pair<String,String>("LK","94"));
    	countryCodes.add(new Pair<String,String>("SD","249"));
    	countryCodes.add(new Pair<String,String>("SR","597"));
    	countryCodes.add(new Pair<String,String>("SJ","47"));
    	countryCodes.add(new Pair<String,String>("SZ","268"));
    	countryCodes.add(new Pair<String,String>("SE","46"));
    	countryCodes.add(new Pair<String,String>("CH","41"));
    	countryCodes.add(new Pair<String,String>("SY","963"));
    	countryCodes.add(new Pair<String,String>("TW","886"));
    	countryCodes.add(new Pair<String,String>("TJ","992"));
    	countryCodes.add(new Pair<String,String>("TZ","255"));
    	countryCodes.add(new Pair<String,String>("TH","66"));
    	countryCodes.add(new Pair<String,String>("TG","228"));
    	countryCodes.add(new Pair<String,String>("TK","690"));
    	countryCodes.add(new Pair<String,String>("TO","676"));
    	countryCodes.add(new Pair<String,String>("TT","1-868"));
    	countryCodes.add(new Pair<String,String>("TN","216"));
    	countryCodes.add(new Pair<String,String>("TR","90"));
    	countryCodes.add(new Pair<String,String>("TM","993"));
    	countryCodes.add(new Pair<String,String>("TC","1-649"));
    	countryCodes.add(new Pair<String,String>("TV","688"));
    	countryCodes.add(new Pair<String,String>("VI","1-340"));
    	countryCodes.add(new Pair<String,String>("UG","256"));
    	countryCodes.add(new Pair<String,String>("UA","380"));
    	countryCodes.add(new Pair<String,String>("AE","971"));
    	countryCodes.add(new Pair<String,String>("GB","44"));
    	countryCodes.add(new Pair<String,String>("US","1"));
    	countryCodes.add(new Pair<String,String>("UY","598"));
    	countryCodes.add(new Pair<String,String>("UZ","998"));
    	countryCodes.add(new Pair<String,String>("VU","678"));
    	countryCodes.add(new Pair<String,String>("VA","379"));
    	countryCodes.add(new Pair<String,String>("VE","58"));
    	countryCodes.add(new Pair<String,String>("VN","84"));
    	countryCodes.add(new Pair<String,String>("WF","681"));
    	countryCodes.add(new Pair<String,String>("EH","212"));
    	countryCodes.add(new Pair<String,String>("YE","967"));
    	countryCodes.add(new Pair<String,String>("ZM","260"));
    	countryCodes.add(new Pair<String,String>("ZW","263"));
    	}

    public String convertCallingCode(String callingCode){
    	String countryCode="";

    	for(int i=0;i<countryCodes.size();++i){
    		if(countryCodes.get(i).second.contentEquals(callingCode)==true) countryCode=countryCodes.get(i).first;
    	}
    	return countryCode;
    }
    
    public String convertCountryCode(String countryCode){
    	String callingCode="";

    	for(int i=0;i<countryCodes.size();++i){
    		if(countryCodes.get(i).first.contentEquals(countryCode)==true) callingCode=countryCodes.get(i).second;
    	}
    	return callingCode;
    }

    public String getImsiSIM1() {
        return imsiSIM1;
    }

    /*public static void setImsiSIM1(String imsiSIM1) {
        TelephonyInfo.imsiSIM1 = imsiSIM1;
    }*/

    public String getImsiSIM2() {
        return imsiSIM2;
    }

    /*public static void setImsiSIM2(String imsiSIM2) {
        TelephonyInfo.imsiSIM2 = imsiSIM2;
    }*/

    public boolean isSIM1Ready() {
        return isSIM1Ready;
    }

    /*public static void setSIM1Ready(boolean isSIM1Ready) {
        TelephonyInfo.isSIM1Ready = isSIM1Ready;
    }*/

    public boolean isSIM2Ready() {
        return isSIM2Ready;
    }

    /*public static void setSIM2Ready(boolean isSIM2Ready) {
        TelephonyInfo.isSIM2Ready = isSIM2Ready;
    }*/

    public boolean isDualSIM() {
        return imsiSIM2 != null;
    }

    private TelephonyInfo() {
    }

    public static TelephonyInfo getInstance(Context context){

        if(telephonyInfo == null) {

            telephonyInfo = new TelephonyInfo();

            telephonyInfo.telephonyManager = ((TelephonyManager) context.getSystemService(Context.TELEPHONY_SERVICE));

            telephonyInfo.imsiSIM1 = telephonyInfo.telephonyManager.getDeviceId();;
            telephonyInfo.imsiSIM2 = null;

            try {
                telephonyInfo.imsiSIM1 = getDeviceIdBySlot(context, "getDeviceIdGemini", 0);
                telephonyInfo.imsiSIM2 = getDeviceIdBySlot(context, "getDeviceIdGemini", 1);
            } catch (GeminiMethodNotFoundException e) {
                e.printStackTrace();

                try {
                    telephonyInfo.imsiSIM1 = getDeviceIdBySlot(context, "getDeviceId", 0);
                    telephonyInfo.imsiSIM2 = getDeviceIdBySlot(context, "getDeviceId", 1);
                } catch (GeminiMethodNotFoundException e1) {
                    //Call here for next manufacturer's predicted method name if you wish
                    e1.printStackTrace();
                }
            }

            telephonyInfo.isSIM1Ready = telephonyInfo.telephonyManager.getSimState() == TelephonyManager.SIM_STATE_READY;
            telephonyInfo.isSIM2Ready = false;

            try {
                telephonyInfo.isSIM1Ready = getSIMStateBySlot(context, "getSimStateGemini", 0);
                telephonyInfo.isSIM2Ready = getSIMStateBySlot(context, "getSimStateGemini", 1);
            } catch (GeminiMethodNotFoundException e) {

                e.printStackTrace();

                try {
                    telephonyInfo.isSIM1Ready = getSIMStateBySlot(context, "getSimState", 0);
                    telephonyInfo.isSIM2Ready = getSIMStateBySlot(context, "getSimState", 1);
                } catch (GeminiMethodNotFoundException e1) {
                    //Call here for next manufacturer's predicted method name if you wish
                    e1.printStackTrace();
                }
            }
        }

        return telephonyInfo;
    }

    private static String getDeviceIdBySlot(Context context, String predictedMethodName, int slotID) throws GeminiMethodNotFoundException {

        String imsi = null;

        TelephonyManager telephony = (TelephonyManager) context.getSystemService(Context.TELEPHONY_SERVICE);

        try{

            Class<?> telephonyClass = Class.forName(telephony.getClass().getName());

            Class<?>[] parameter = new Class[1];
            parameter[0] = int.class;
            Method getSimID = telephonyClass.getMethod(predictedMethodName, parameter);

            Object[] obParameter = new Object[1];
            obParameter[0] = slotID;
            Object ob_phone = getSimID.invoke(telephony, obParameter);

            if(ob_phone != null){
                imsi = ob_phone.toString();

            }
        } catch (Exception e) {
            e.printStackTrace();
            throw new GeminiMethodNotFoundException(predictedMethodName);
        }

        return imsi;
    }

    private static boolean getSIMStateBySlot(Context context, String predictedMethodName, int slotID) throws GeminiMethodNotFoundException {

        boolean isReady = false;

        TelephonyManager telephony = (TelephonyManager) context.getSystemService(Context.TELEPHONY_SERVICE);

        try{

            Class<?> telephonyClass = Class.forName(telephony.getClass().getName());

            Class<?>[] parameter = new Class[1];
            parameter[0] = int.class;
            Method getSimStateGemini = telephonyClass.getMethod(predictedMethodName, parameter);

            Object[] obParameter = new Object[1];
            obParameter[0] = slotID;
            Object ob_phone = getSimStateGemini.invoke(telephony, obParameter);

            if(ob_phone != null){
                int simState = Integer.parseInt(ob_phone.toString());
                if(simState == TelephonyManager.SIM_STATE_READY){
                    isReady = true;
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
            throw new GeminiMethodNotFoundException(predictedMethodName);
        }

        return isReady;
    }

    public int getDefaultSim() {
//http://stackoverflow.com/questions/32088950/how-to-check-which-sim-is-set-as-default-sim-in-android-programatically
        Method method_getDefaultSim;
        int defaultSim=-1;
        try {
            method_getDefaultSim = telephonyManager.getClass().getDeclaredMethod("getDefaultSim");
            method_getDefaultSim.setAccessible(true);
            defaultSim=(Integer) method_getDefaultSim.invoke(telephonyManager);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return defaultSim;
    }

    public int getSmsDefaultSim() {
//http://stackoverflow.com/questions/32088950/how-to-check-which-sim-is-set-as-default-sim-in-android-programatically
        Method method_getSmsDefaultSim;
        int smsDefaultSim = -1;
        try {
            method_getSmsDefaultSim = telephonyManager.getClass().getDeclaredMethod("getSmsDefaultSim");
            smsDefaultSim = (Integer) method_getSmsDefaultSim.invoke(telephonyManager);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return smsDefaultSim;
    }

    private static class GeminiMethodNotFoundException extends Exception {

        private static final long serialVersionUID = -996812356902545308L;

        public GeminiMethodNotFoundException(String info) {
            super(info);
        }
    }

    public static void printTelephonyManagerMethodNamesForThisDevice(Context context) {

        TelephonyManager telephony = (TelephonyManager) context.getSystemService(Context.TELEPHONY_SERVICE);
        Class<?> telephonyClass;
        try {
            telephonyClass = Class.forName(telephony.getClass().getName());
            Method[] methods = telephonyClass.getMethods();
            for (int idx = 0; idx < methods.length; idx++) {

                System.out.println("\n" + methods[idx] + " declared by " + methods[idx].getDeclaringClass());
            }
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}