import java.util.LinkedList
import kotlin.math.max

class Solution {
    fun solution(queue1: IntArray, queue2: IntArray): Int {
        val impossible = -1

        val q1 = ArrayDeque(queue1.toList())
        val q2 = ArrayDeque(queue2.toList())

        var sum: Long = 0
        queue1.map { sum += it }
        queue2.map { sum += it }

        if(sum % 2 == 1L) return impossible

        sum /= 2

        var count = 0

        val maxLimit = queue1.size * 2

        var queue1Count = 0
        var queue2Count = 0

        var queue1Sum: Long = 0
        var queue2Sum: Long = 0

        queue1.map { queue1Sum += it }
        queue2.map { queue2Sum += it }

        while (queue1Count < maxLimit && queue2Count < maxLimit) {
            if(queue1Sum == queue2Sum) return queue1Count + queue2Count
            if(queue1Sum > queue2Sum) {
                val num = q1.removeFirst()
                queue1Sum -= num
                queue2Sum += num
                q2.add(num)
                queue1Count++
            } else {
                val num = q2.removeFirst()
                queue1Sum += num
                queue2Sum -= num
                q1.add(num)
                queue2Count++
            }
        }

        return impossible
    }
}