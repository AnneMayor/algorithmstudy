public class Solution {
    public int minimumAverageDifference(int[] nums) {
        long start = 0, n = nums.length;
        long total = 0;

        for(int num : nums) {
            total += num;
        }

        int cnt = 1;
        long currentAbsoluteDiff = Integer.MAX_VALUE;
        int res = -1;
        for(int index = 0; index < n; index++) {
            start += nums[index];

            long temp = (n - cnt) > 0 ? (total - start) / (n - cnt) : 0;
            long absoluteDiff = Math.abs(start / cnt - temp);

            if(currentAbsoluteDiff > absoluteDiff) {
                currentAbsoluteDiff = absoluteDiff;
                res = index;
            }

            cnt++;
        }

        return res;
    }
}