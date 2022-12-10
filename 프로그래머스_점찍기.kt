import kotlin.math.*

class Solution {
    fun solution(k: Int, d: Int): Long {
        var answer: Long = 0

//        for (i in 0..d / k) {
//            val num = i * k
//
//            val leftNumber = d.toDouble().pow(2.toDouble()) - num.toDouble().pow(2.toDouble())
//            answer += sqrt(leftNumber).toInt() / k + 1
//        }

        // step 문법 활용
        for (i in 0..d step k) {
            val leftNumber = d.toDouble().pow(2.toDouble()) - i.toDouble().pow(2.toDouble())
            answer += sqrt(leftNumber).toInt() / k + 1
        }

        return answer
    }
}