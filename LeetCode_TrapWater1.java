public class Solution {
    public int trap(int[] height) {
        int maxLeft = 0, maxRight = 0, left = 0, right = height.length - 1;

        int ans = 0;

        while(left < right) {
            if(height[left] < height[right]) {
                maxLeft = Math.max(maxLeft, height[left]);
                ans += maxLeft - height[left];
                left++;
            } else {
                maxRight = Math.max(maxRight, height[right]);
                ans += maxRight - height[right];
                right--;
            }
        }

        return ans;
    }
}
