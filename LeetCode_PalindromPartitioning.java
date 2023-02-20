public class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        boolean[][] dp = new boolean[s.length()][s.length()];

        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j <= i; j++) {
                if (s.charAt(i) == s.charAt(j) && (i - j <= 2 || dp[j+1][i-1])) {
                    dp[j][i] = true;
                }
            }
        }

        palindromPartitioning(dp, ans, s, new ArrayList<String>(), 0);

        return ans;
    }

    public void palindromPartitioning(boolean[][] dp, List<List<String>> ans, String s, List<String> temp, int pos) {
        if (pos == s.length()) {
            ans.add(new ArrayList<>(temp));
            return ;
        }

        for (int i = pos; i < s.length(); i++) {
            if (dp[pos][i]) {
                temp.add(s.substring(pos, i + 1));
                palindromPartitioning(dp, ans, s, temp, i + 1);
                temp.remove(temp.size() - 1);
            }
        }
    }
}