public class LeetCode_maxArea {

    public int maxArea(int[] height) {

        int left = 0, right = height.length - 1;

        int maxArea = 0;

        while(left < right) {
            maxArea = Math.max(maxArea, (right - left) * Math.min(height[left], height[right]));
            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        

        return maxArea;
    }
}
