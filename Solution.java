public class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int nonCircularArrSum = kadaneMaxAlgorithm(nums);
        int totalSum = 0;
        int length = nums.length;
        for (int index = 0; index < length; index++) {
            totalSum += nums[index];
            nums[index] = -nums[index];
        }
        
        int circularArrSum = totalSum + kadaneMaxAlgorithm(nums);

        if (circularArrSum == 0) return nonCircularArrSum;
        
        return Math.max(nonCircularArrSum, circularArrSum);
    }
    
    public int kadaneMaxAlgorithm(int[] nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];

        int length = nums.length;
        for (int index = 1; index < length; index++) {
            if (currentSum < 0) currentSum = 0;
            currentSum += nums[index];

            maxSum = Math.max(maxSum, currentSum);
        }

        return maxSum;
    }
}