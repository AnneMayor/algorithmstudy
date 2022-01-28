import java.util.ArrayList;
import java.util.List;


// Time: O(nm * min(n,m)) | Space: O(nm*min(n, m))
public class AlgoExpert_LongestCommonSubsequence_Before_Optimal {

    public static List<Character> longestCommonSubsequence(String str1, String str2) {

        List<List<List<Character> > > lcs = new ArrayList<>();

        int st1Len = str1.length();
        int st2Len = str2.length();

        for(int i = 0; i <= st1Len; i++) {
            lcs.add(new ArrayList<>());
            for(int j = 0; j <= st2Len; j++) {
                lcs.get(i).add(new ArrayList<>());
            }
        }

        for(int i = 1; i <= st1Len; i++) {
            for(int j = 1; j <= st2Len; j++) {
                if(str1.charAt(i-1) == str2.charAt(j-1)) {
                    List<Character> copy = new ArrayList<>(lcs.get(i-1).get(j-1));
                    lcs.get(i).set(j, copy);
                    lcs.get(i).get(j).add(str1.charAt(i-1));
                } else {
                    if(lcs.get(i-1).get(j).size() > lcs.get(i).get(j-1).size()) {
                        lcs.get(i).set(j, lcs.get(i-1).get(j));
                    } else {
                        lcs.get(i).set(j, lcs.get(i).get(j-1));
                    }
                }
            }
        }
        
        return lcs.get(st1Len).get(st2Len);
      }
    
}
