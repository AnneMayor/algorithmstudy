import java.net.ProtocolFamily;
import java.util.ArrayList;
import java.util.HashMap;

public class Solution {

    public static HashMap<String, String> sellerTree;
    public static HashMap<String, Integer> sellerAmount;
    public static int totalIncome;

    public ArrayList<Integer> solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        ArrayList<Integer> answer = new ArrayList<>();
        sellerTree = new HashMap<>();
        sellerAmount = new HashMap<>();

        sellerTree.put("center", "");
        for(String name : enroll) {
            sellerTree.put(name, "");
        }

        int count = enroll.length;
        for(int i = 0; i < count; i++) {
            if(referral[i].equals("-")) {
                sellerTree.put(enroll[i], "center");
            } else {
                sellerTree.put(enroll[i], referral[i]);
            }
        }

        sellerAmount.put("center", 0);
        for(String name : enroll) {
            sellerAmount.put(name, 0);
        }

        int sellerCount = seller.length;
        for(int i = 0; i < sellerCount; i++) {
            totalIncome = amount[i] * 100;
            int profit = (int) (totalIncome * 0.1);
            sellerAmount.put(seller[i], sellerAmount.get(seller[i]) + totalIncome - profit);
            totalIncome = profit;
            trackSellers(seller[i]);
        }

        for(String name : enroll) {
            int profit = sellerAmount.get(name).intValue();
            answer.add(profit);
        }

        return answer;
    }

    public void trackSellers(String name) {
        String parent = sellerTree.get(name);

        if(parent.equals("")) return ;
        if(totalIncome <= 0) return ;

        int profit = (int)(totalIncome * 0.1);

        // System.out.println("seller: " + name + ", parent: " + parent + ", profit: " + profit);

        sellerAmount.put(parent, sellerAmount.get(parent) + totalIncome - profit);

        totalIncome = profit;
        // System.out.println("totalIncome: " + totalIncome);
        trackSellers(parent);
    }
}