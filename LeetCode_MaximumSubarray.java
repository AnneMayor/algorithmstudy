public class Solution {
    public int maxSubArray(int[] nums) {
        return kadaneAlgorithm(nums);
    }

    public int kadaneAlgorithm(int[] nums) {
        int maxSum = 0;
        int currentSum = 0;

        int size = nums.length;
        for (int index = 0; index < size; index++) {
            currentSum = Math.max(currentSum, 0) + nums[index];
            maxSum = Math.max(maxSum, currentSum);
        }

        return maxSum;
    }
}