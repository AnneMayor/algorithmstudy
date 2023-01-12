public class LeetCode_ValidAnagram {
    public boolean isAnagram(String s, String t) {
        int []  cntOfAlphabet = new int[30];
        
        int sLen = s.length();

        for(int i = 0; i < sLen; i++) {
            cntOfAlphabet[s.charAt(i)-'a']++;
        }

        int tLen = t.length();

        for(int i = 0; i < tLen; i++) {
            if(cntOfAlphabet[t.charAt(i)-'a'] > 0) cntOfAlphabet[t.charAt(i)-'a']--;
            else cntOfAlphabet[t.charAt(i)-'a']++;
            // else return false;
        }

        int totalCountOfLeftAlphabet = 0;
        for(int i = 0; i < 30; i++) {
            totalCountOfLeftAlphabet += cntOfAlphabet[i];
        }

        System.out.println(totalCountOfLeftAlphabet);

        return totalCountOfLeftAlphabet == 0 ? true : false;
    }
}
