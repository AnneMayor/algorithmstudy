public class Solution {
    public int findJudge(int n, int[][] trust) {
        Map<Integer, Integer> trusts = new HashMap<>();
        boolean[] trusting = new boolean[n + 1];

        if (n == 1) return n;

        for (int [] t : trust) {
            trusting[t[0]] = true;
            trusts.put(t[1], trusts.getOrDefault(t[1], 0) + 1);
        }

        for (int i = 1; i <= n; i++) {
            if (trusts.get(i) != null && trusts.get(i) == n - 1 && !trusting[i]) {
                return i;
            }
        }

        return -1;
    }
}