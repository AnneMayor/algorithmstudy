import kotlin.math.max
import kotlin.math.min

class Solution {
    private val MAX_SIZE = 200
    fun solution(alp: Int, cop: Int, problems: Array<IntArray>): Int {
        var dp: Array<IntArray> = Array(MAX_SIZE){ IntArray(MAX_SIZE){Integer.MAX_VALUE} }
        var max_alp = 0
        var max_cop = 0

        problems.map {problem ->
            max_alp = max(max_alp, problem[0])
            max_cop = max(max_cop, problem[1])
        }
        dp[min(alp, max_alp)][min(cop, max_cop)] = 0

        for(i in min(alp, max_alp)..max_alp) {
            for(j in min(cop, max_cop)..max_cop) {
                if (i+1 <= max_alp) {
                    dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1)
                }

                if(j+1 <= max_cop) {
                    dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1)
                }

                problems.map { problem ->
                    if(i >= problem[0] && j >= problem[1]) {
                        val newI = min(i + problem[2], max_alp)
                        val newJ = min(j + problem[3], max_cop)

                        dp[newI][newJ] = min(dp[newI][newJ], dp[i][j] + problem[4])
                    }
                }
            }
        }

        return dp[max_alp][max_cop]
    }
}