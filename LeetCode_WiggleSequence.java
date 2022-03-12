public class LeetCode_WiggleSequence {
    public int wiggleMaxLength(int[] nums) {
        int diff = 0;
        int n = nums.length;
        int ans = n;
        int prevSign = 0;
        for(int i = 1; i < n; i++) {
            diff = nums[i] - nums[i-1];
            if(diff == 0) {
                ans--;
                continue;
            }
            
            int curSign = diff > 0 ? 1 : -1;
            if(prevSign == curSign) ans--;
            prevSign = curSign;
        }
        
        return ans;
    }
}
