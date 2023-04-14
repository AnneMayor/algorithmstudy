public class Solution {
    public int superEggDrop(int k, int n) {
        int[] dp = new int[k+1];
        int numOfMoves = 0;

        for (; dp[k] < n; numOfMoves++) {
            for (int i = k; i > 0; i-- ) {
                dp[i] += dp[i-1] + 1;
            }
        }

        return numOfMoves;
    }

    public int superEggDrop_ONK_Time(int k, int n) {
        int [][] dp = new int[k+1][n+1];

        int res = 0;

        for (; dp[k][res] < n; res++) {
            for (int tk = 1; tk <= k; tk++) {
                dp[tk][res] = dp[tk-1][res-1] + 1 + dp[tk][res-1];
            }
        }

        return res;
    }

    public int combination(int n, int k, int mid) {
        int res = 1;
        int ans = 0;

        for (int i = 1; i <= k; i++) {
            res *= (mid - (i - 1));
            res /= i;
            ans += res;
            if (ans >= n) return ans;
        }

        return ans;
    }

    public int superEggDrop(int k, int n) {
        int left = 1, right = n;

        while (left <= right) {
            int mid = (left + right) / 2;

            int temp = 0;
            temp = combination(n, k, mid);

            if (temp == n) return mid;

            if (temp > n) right = mid - 1;
            else left = mid + 1;
        }

        return left;
    }

    public int superEggDrop(int k, int n) {

    }
}