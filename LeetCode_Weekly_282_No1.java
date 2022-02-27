public class LeetCode_Weekly_282_No1 {
    public int prefixCount(String[] words, String pref) {
        int res = 0;
        
        for(String word : words) {
            int prefLength = pref.length();
            int wordLength = word.length();
            if(prefLength > wordLength) continue;
            else if(prefLength == wordLength) res = pref.equals(word) ? res + 1 : res;
            else {
                String temp = word.substring(0, prefLength);
                if(pref.equals(temp)) res++;
            }
        }
        
        return res;
    }
}
