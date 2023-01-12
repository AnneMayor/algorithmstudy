public class LeetCode_WeeklyContent_298_No3 {
    public int longestSubsequence(String s, int k) {

        int sn = s.length();

        String ans = "";
        boolean isValid = true;
        String binaryK = Integer.toBinaryString(k);
        
        for(int i = sn-1; i >= 0; i--) {
            if(isValid) {
                if(binaryK.length() <= ans.length()) {
                    if(s.charAt(i) == '1') continue;
                }
                
                long decimal = Long.parseLong(s.charAt(i) + ans, 2);
                if(k >= decimal) ans = s.charAt(i) + ans;
                else isValid = false;
            } else {
                if(s.charAt(i) == '0') ans = s.charAt(i) + ans;
            }
        }
        
        return ans.length();
    }
}
