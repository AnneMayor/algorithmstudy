public class LeetCode_PermutationString {
    public boolean checkInclusion(String s1, String s2) {
        int count = 0;
        int [] s1Map = new int[26];
        int [] s2Map = new int[26];

        int s1Len = s1.length();
        int s2Len = s2.length();

        if(s1Len > s2Len) return false;

        for(int i = 0; i < s1Len; i++) {
            int s1CharInt = s1.charAt(i) - 'a';
            int s2CharInt = s2.charAt(i) - 'a';
            s1Map[s1CharInt]++;
            s2Map[s2CharInt]++;
        }

        for(int i = 0; i < 26; i++) {
            if(s1Map[i] == s2Map[i]) count++;
        }

        for(int i = 0; i < s2Len - s1Len; i++) {
            if(count == 26) return true;
            int r = s2.charAt(i+s1Len) - 'a', l = s2.charAt(i) - 'a';
            s2Map[r]++;
            if(s1Map[r] == s2Map[r]) count++;
            else if(s2Map[r] == s1Map[r] + 1) count--;
            s2Map[l]--;
            if(s2Map[l] == s1Map[l]) count++;
            else if(s2Map[l] == s1Map[l] - 1) count--;
        }
        
        return count == 26;
    }
}
