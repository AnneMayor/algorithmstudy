class Solution {
    public int bestRotation(int[] nums) {
        int n = nums.length;
        int[] change = new int[n];

        // find lose point
    for(int i = 0; i < n; i++) {
        change[(i-nums[i]+n+1)%n]--;
    }

    // find max k
    int maxK = 0;
    for(int i = 1; i < n; i++) {
        change[i] += change[i-1] + 1;
        maxK = change[i] > change[maxK] ? i : maxK;
    }

    return maxK;
    }
}