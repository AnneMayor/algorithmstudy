import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

class Solution {
    public HashMap<String, Integer> possibleCoursePerClient;
    public ArrayList<String> solution(String[] orders, int[] course) {
        ArrayList<String> answer = new ArrayList<>();

        possibleCoursePerClient = new HashMap<>();
        boolean [] isVisited = new boolean[30];

        int ordersLen = orders.length;
        for(int i = 0; i < ordersLen; i++) {
            char [] orderCharArr = orders[i].toCharArray();
            Arrays.sort(orderCharArr);
            orders[i] = String.valueOf(orderCharArr);
        }

        for(int courseCount : course) {
            for(int i = 0; i < ordersLen; i++) {
                Arrays.fill(isVisited, false);
                combination("", orders[i], courseCount);
            }

            if(!possibleCoursePerClient.isEmpty()) {
                List<Integer> possibleValues = new ArrayList<>(possibleCoursePerClient.values());
                int maxValue = Collections.max(possibleValues);

                if(maxValue <= 1) continue;

                for(String key : possibleCoursePerClient.keySet()) {
                    if(possibleCoursePerClient.get(key) == maxValue) {
                        answer.add(key);
                    }
                }
            }

            possibleCoursePerClient.clear();
        }

        Collections.sort(answer);

        return answer;
    }

    public void combination(String target, String order, int count) {

        if(count == 0) {
            possibleCoursePerClient.put(target, possibleCoursePerClient.getOrDefault(target, 0)+1);
            return ;
        }

        for(int i = 0; i < order.length(); i++) {
            combination(target+order.charAt(i), order.substring(i+1), count-1);
        }
    }
}