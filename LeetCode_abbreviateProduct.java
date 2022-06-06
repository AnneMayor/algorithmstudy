public class LeetCode_abbreviateProduct {
    private final long THRESHOLD1 = 100_000_000_000_000L;
    private final long THRESHOLD2 = 10_000_000_000L;
    private final int THRESHOLD3 = 100_000;

    public String abbreviateProduct(int left, int right) {
        long currentNum = 1L;

        int num = left, trailingZeros = 0;
        for(; num <= right && currentNum < THRESHOLD1; num++) {
            currentNum *= num;

            while(currentNum % 10 == 0) {
                currentNum /= 10;
                trailingZeros++;
            }
        }

        if(currentNum < THRESHOLD2) return String.format("%de%d", currentNum, trailingZeros);

        long lower = currentNum % THRESHOLD2;
        double upper = currentNum;

        while(upper > THRESHOLD2) upper /= 10;

        for(;num <= right; num++) {
            upper *= num;
            lower *= num;

            while(lower % 10 == 0) {
                trailingZeros++;
                lower /= 10;
            }

            if(lower >= THRESHOLD2) lower %= THRESHOLD2;
            while(upper > THRESHOLD2) upper /= 10;
        }

        while(upper >= THRESHOLD3) upper /= 10;
        lower %= THRESHOLD3;

        return String.format("%d...%05de%d", (int) upper, lower, trailingZeros);
    }
}