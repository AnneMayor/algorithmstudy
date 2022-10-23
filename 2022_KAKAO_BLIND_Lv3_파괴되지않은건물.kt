class Solution {

    // 누적합을 이용한 효율적인 풀이
    fun solution(board: Array<IntArray>, skill: Array<IntArray>): Int {
        var answer: Int = 0

        var buildingStatus: Array<IntArray> = Array(board.size+1){IntArray(board[0].size + 1){0} }

        skill.map {
            val type = it[0]
            val r1 = it[1]
            val c1 = it[2]
            val r2 = it[3]
            val c2 = it[4]
            var degree = it[5]

            when(type) {
                1 -> degree = -degree
            }

            buildingStatus[r1][c1] += degree
            buildingStatus[r2+1][c2+1] += degree
            buildingStatus[r1][c2+1] -= degree
            buildingStatus[r2+1][c1] -= degree
        }

        for (row in buildingStatus.indices) {
            for (col in 1 until buildingStatus[0].size) {
                buildingStatus[row][col] += buildingStatus[row][col-1]
            }
        }

        for (col in buildingStatus[0].indices) {
            for (row in 1 until buildingStatus.size) {
                buildingStatus[row][col] += buildingStatus[row-1][col]
            }
        }

        for (row in board.indices) {
            for(col in board[0].indices) {
                if(board[row][col] + buildingStatus[row][col] > 0) answer++
            }
        }

        return answer
    }
}