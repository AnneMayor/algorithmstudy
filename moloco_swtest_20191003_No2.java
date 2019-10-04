import java.util.Scanner;
import java.util.Hashtable;
import java.util.ArrayList;

public class moloco_swtest_20191003_No2 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Hashtable<String, ArrayList<String> > htCond1 = new Hashtable<String, ArrayList<String> >();
        Hashtable<String, Integer> htCond2 = new Hashtable<String, Integer>();
        ArrayList<String> keyList = new ArrayList<>();

        while(sc.hasNextLine()){
            String s;
            s = sc.nextLine();
            // For getting the answer in my IDE tool
            if(s.equals("") || null == s) break;
            int lastIdx = s.length()-1;
            s = s.substring(1, lastIdx);
            String str [] = new String[3];
            str = s.split(",");
            String [][] stList = new String[3][2];

            for(int i = 0; i < 3; i++) {
                stList[i] = str[i].split(":");
            }

            for(int i = 0; i < 3; i++) {
                stList[i][1] = stList[i][1].substring(1);
            }

            if(htCond1.containsKey(stList[1][1])) {

                ArrayList<String> arrList = htCond1.get(stList[1][1]);
                int arrSize = arrList.size();
                boolean flag = true;

                for(int i = 0; i < arrSize; i++) {
                    if(stList[0][1].equals(arrList.get(i))) {
                        flag = false;
                        break;
                    }
                }

                if(flag) htCond1.get(stList[1][1]).add(stList[0][1]);

            } else {
                ArrayList<String> tmp = new ArrayList<>();
                tmp.add(stList[0][1]);
                htCond1.put(stList[1][1], tmp);
                keyList.add(stList[1][1]);
            }

            if(htCond2.containsKey(stList[1][1])) {
                int tmp = htCond2.get(stList[1][1]) + Integer.parseInt(stList[2][1]);
                htCond2.put(stList[1][1], tmp);
            } else {
                htCond2.put(stList[1][1], Integer.parseInt(stList[2][1]));
                keyList.add(stList[1][1]);
            }
        }

        String ansCond1 = "";
        String ansCond2 = "";
        int numOfPurchasers = -1, numOfQuantity = -1;
        int arrSize = keyList.size();
        for(int i = 0; i < arrSize; i++) {
            if(numOfPurchasers < htCond1.get(keyList.get(i)).size()) {
                ansCond1 = keyList.get(i);
                numOfPurchasers = htCond1.get(keyList.get(i)).size();
            }

            if(numOfQuantity < htCond2.get(keyList.get(i))) {
                ansCond2 = keyList.get(i);
                numOfQuantity = htCond2.get(keyList.get(i));
            }
        }

        System.out.println("Most popular product(s) based on the number of purchasers: " + ansCond1);
        System.out.println("Most popular product(s) based on the quantity of goods sold: " + ansCond2);
        
    }

}