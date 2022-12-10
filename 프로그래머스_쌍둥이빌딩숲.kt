class Solution {
    fun solution(n: Int, count: Int): Int {
        val dividend: Long = 1000000007
        val dp: Array<Long> = Array(count+1){0}

        dp[1] = 1

        for (i in 1..n-1) {
            val multiplyConstant = 2 * i

            for (j in count downTo 1) {
                dp[j] = (dp[j-1] + dp[j] * multiplyConstant) % dividend
            }
        }

        return dp[count].toInt()
    }
}