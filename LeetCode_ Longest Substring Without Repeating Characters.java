public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int [] cntOfAlphbet = new int[256];

        int l = 0, r = 0;
        int n = s.length();
        int result = 0;

        while(r < n) {
            char right = s.charAt(r);
            cntOfAlphbet[right]++;
            r++;

            while(cntOfAlphbet[right] > 1) {
                char left = s.charAt(l);
                cntOfAlphbet[left]--;
                l++;
            }

            result = Math.max(result, r-l);
        }
        

        return result;
    }
}