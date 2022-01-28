import java.util.ArrayList;
import java.util.List;

// Briliiant한 방법...간략하게 그림으로 소개
//   '' A A A A
// '' 0(end) 0 0 0 0
// A 0 1 1 1 1
//     ^
// B 0 1 1 1 1
//     ^
// C 0 1(move) 1 1 1
// A 0 1 2 <- 2 <- 2(start)
// 요약: LCS 길이만으로 다음과 같이 트래킹이 가능. 잘 알아뒀다 나중에 써먹어야지...!
// Time: O(nm) | Space: O(nm)
public class AlgoExpert_LongestCommonSequence_After_Optimal {

    public static List<Character> longestCommonSubsequence(String str1, String str2) {
        int [][] lengths = new int[str1.length()+1][str2.length() + 1];

        int st1Len = str1.length();
        int st2Len = str2.length();

        for(int i = 1; i <= st1Len; i++) {
            for(int j = 1; j <= st2Len; j++) {
                if(str1.charAt(i-1) == str2.charAt(j-1)) {
                    lengths[i][j] = lengths[i-1][j-1] + 1;
                } else {
                    lengths[i][j] = Math.max(lengths[i-1][j], lengths[i][j-1]);
                }
            } 
        }

        return buildSequence(lengths, str1);
      }

    public static List<Character> buildSequence(int [][] lengths, String str) {
        List<Character> sequence = new ArrayList<>();

        int i = lengths.length-1;
        int j = lengths[0].length-1;

        while(i != 0 && j != 0) {
            // if문은 웬만하면 else if로 정확하게 분기해주도록 하자...!안그럼 로직에서 꼬인다!
            if(lengths[i][j] == lengths[i-1][j]) i--;
            else if(lengths[i][j] == lengths[i][j-1]) j--;
            else {
                sequence.add(0, str.charAt(i-1));
                i--;
                j--;
            }
        }
        
        return sequence;
    }
}