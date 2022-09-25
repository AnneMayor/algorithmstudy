import java.util.*

class Solution {
    var answer: IntArray = intArrayOf(Int.MAX_VALUE, Int.MAX_VALUE)

    fun solution(n: Int, paths: Array<IntArray>, gates: IntArray, summits: IntArray): IntArray {
        val graph = Array(n + 1) { mutableListOf<Pair<Int, Int>>() }

        val gateSet = gates.toSet()
        val summitSet = summits.toSet()

        paths.forEach {
            graph[it[0]].add(it[1] to it[2])
            graph[it[1]].add(it[0] to it[2])
        }

        gates.forEach { gate ->
            course(gate, graph, BooleanArray(n + 1), gateSet, summitSet)
        }

        return answer
    }

    fun course(start: Int, graph: Array<MutableList<Pair<Int, Int>>>, visited: BooleanArray, gateSet: Set<Int>, summitSet: Set<Int>) {
        val q = PriorityQueue<Pair<Int, Int>>(compareBy({ it.second }, { it.first }))
        q.add(start to 0)

        while (q.isNotEmpty()) {
            val (now, time) = q.poll()

            if (now in summitSet) {
                answer = minOf(answer, intArrayOf(now, time), compareBy({ it.last() }, { it.first() }))
                break
            }

            visited[now] = true

            graph[now].forEach { (next, t) ->
                if (next !in gateSet && !visited[next]) q.add(next to maxOf(t, time))
            }
        }
    }
}
