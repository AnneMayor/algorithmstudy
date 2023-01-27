public class Solution {
    public int minFlipsMonoIncr(String s) {
        // dynamic windows
        //        return dynamicWindows(s);

        // dynamic programming
        return dynamicProgramming(s);
    }

    public int dynamicWindows(String s) {
        char[] arrs = s.toCharArray();

        int countOfZeros = 0;
        for (char c : arrs) {
            if (c == '0') countOfZeros++;
        }
        int ans = countOfZeros;

        for (char c : arrs) {
            if (c == '0') {
                ans = Math.min(ans, --countOfZeros);
            } else {
                countOfZeros++;
            }
        }

        return ans;
    }

    public int dynamicProgramming(String s) {
        char[] arrs = s.toCharArray();

        int ans = 0;
        int nums = 0;

        for (char c : arrs) {
            if (c == '0') {
                ans = Math.min(nums, ans + 1);
            } else {
                nums++;
            }
        }

        return ans;
    }
}