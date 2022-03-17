public class LeetCode_WiggleMaxLength {
    public int wiggleMaxLength(int[] nums) {
        int n = nums.length;
        int ans = n;
        
        int [] up = new int[n];
        int [] down = new int[n];
        
        if(n < 2) return n;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] < nums[j]) {
                    down[i] = Math.max(down[i], up[j] + 1);
                } else if(nums[i] > nums[j]) {
                    up[i] = Math.max(up[i], down[j] + 1);
                }
            }
        }

        ans = Math.max(up[n-1], down[n-1])+1;
        return ans;
    }

    public int wiggleMaxLength_Optimized_Time_Complexity(int[] nums) {
        int n = nums.length;
        
        int [] up = new int[n];
        int [] down = new int[n];
        
        if(n < 2) return n;
        
        up[0] = down[0] = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            } else if(nums[i] < nums[i-1]) {
                down[i] = up[i-1] + 1;
                up[i] = up[i-1];
            } else {
                down[i] = down[i-1];
                up[i] = up[i-1];
            }
        }
        
        return Math.max(up[n-1], down[n-1]);
    }

    public int wiggleMaxLength_Optimized_Time_And_Space_Complexity(int[] nums) {
        int n = nums.length;
        int count = 0;
        
        if(n < 2) return n;

        int prevDiff = nums[1] - nums[0];
        count = prevDiff != 0 ? 2 : 1;

        for(int i = 2; i < n; i++) {
            int diff = nums[i] - nums[i-1];
            if((diff < 0 && prevDiff >= 0) || (diff > 0 && prevDiff <= 0)) {
                count++;
                prevDiff = diff;
            }
        }
        
        return count;
    }
}
