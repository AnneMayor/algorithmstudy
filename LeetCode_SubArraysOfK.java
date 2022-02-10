import java.util.HashMap;

public class LeetCode_SubArraysOfK {
    public int subarraySum(int[] nums, int k) {
        int answer = 0;

        int startNum = 0;
        
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        
        for(int num : nums) {
            startNum += num;
            if(map.containsKey(startNum - k)) answer += map.get(startNum - k);
            if(!map.containsKey(startNum)) map.put(startNum, 1);
            else map.put(startNum, map.get(startNum)+1);
        }

        return answer;
    }
}
