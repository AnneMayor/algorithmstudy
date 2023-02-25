public class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int runningSum = 0;
        Map<Integer, Integer> map = new HashMap<>(){{put(0, -1);}};
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            runningSum += nums[i];
            if (k != 0) runningSum %= k;
            int prev = map.getOrDefault(runningSum, Integer.MAX_VALUE);
            if (prev != Integer.MAX_VALUE) {
                if (i - prev > 1) return true;
            } else {
                map.put(runningSum, i);
            }
        }

        return false;
    }
}