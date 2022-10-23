public class LeetCode_MinimumTimeToMakeRopeColorful {
    public int minCost(String colors, int[] neededTime) {
        char current = colors.charAt(0);
        int currentIndex = 0;

        int len = colors.length();
        int res = 0;
        for(int index = 1; index < len; index++) {
            if(current == colors.charAt(index)) {
                res += Math.min(neededTime[index], neededTime[currentIndex]);
                currentIndex = neededTime[index] > neededTime[currentIndex] ? index : currentIndex;
            } else {
                current = colors.charAt(index);
                currentIndex = index;
            }
        }

        return res;
    }
}