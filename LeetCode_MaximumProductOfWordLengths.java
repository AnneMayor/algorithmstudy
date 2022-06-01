import java.util.Arrays;

public class LeetCode_MaximumProductOfWordLengths {
    public int maxProduct(String[] words) {
        int n = words.length;

        int ans = 0;
        int [] checkAlphabet = new int[30];

        for(int i = 0; i < n; i++) {
            for(int j = i+1;  j < n; j++) {

                Arrays.fill(checkAlphabet, 0);

                int firstN = words[i].length(), secondN = words[j].length();
                for(int x = 0; x < firstN; x++) {
                    checkAlphabet[words[i].charAt(x) - 'a'] = 1;
                }

                boolean hasCommonCharacter = false;

                for(int y = 0; y < secondN; y++) {
                    if(checkAlphabet[words[j].charAt(y) - 'a'] == 1) {
                        hasCommonCharacter = true;
                        break;
                    }
                }

                if(!hasCommonCharacter) {
                    ans = Math.max(ans, firstN * secondN);
                }

            }
        }

        return ans;
    }
}
