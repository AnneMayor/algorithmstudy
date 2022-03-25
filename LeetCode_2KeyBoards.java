public class LeetCode_2KeyBoards {

    public int minSteps(int n) {
        int startValue = 1;
        int res = 0;
        int digit = 0;

        while(n > startValue) {
            if(n % startValue == 0) {
                digit = startValue;
                startValue += digit;
                res += 2;
            } else {
                startValue += digit;
                res++;
            }
        }

        return res;
    }
    
}
