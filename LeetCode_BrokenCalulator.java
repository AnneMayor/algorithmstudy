public class LeetCode_BrokenCalulator {
    public int brokenCalc(int startValue, int target) {
        // reverse tracking
        int res = 0;
        
        while(target > startValue) {
            res++;
            if(target % 2 == 0) {
                target /= 2;
            } else {
                target++;
            }
        }

        return res + (startValue - target);
    }
}
