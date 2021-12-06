public class 프로그래머스_멀쩡한_사각형 {

    // 최대공약수를 이용한 문제
    // 겹치는 사각형 개수: w + h - GCD(w, h)
    // 겹치는 구간 문제에서는 최대공약수 개념도 한번 생각해볼 필요가 있음을 배웠다!

    public int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a%b);
    }

    public long solution(int w, int h) {
        long answer = 1;
        long totalSquare = (long) w * h;
        answer = totalSquare - (w+h-gcd(w, h));
        return answer;
    }
}
