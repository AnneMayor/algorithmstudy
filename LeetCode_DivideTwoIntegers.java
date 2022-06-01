public class LeetCode_DivideTwoIntegers {
    public int divide(int dividend, int divisor) {
        if(dividend == Integer.MIN_VALUE && divisor == -1) return Integer.MAX_VALUE;
        long absDividend = Math.abs((long)dividend), absDivisor = Math.abs((long)divisor);

        int ans = 0;
        while(absDividend - absDivisor >= 0) {
            long tempDivisor = absDivisor;
            long count = 1;
            while(absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                count <<= 1;
            }

            ans += count;
            
            absDividend -= tempDivisor;
        }

        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) return -ans;
        return ans;
    }
}