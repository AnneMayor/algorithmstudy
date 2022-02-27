import java.util.Arrays;

public class LeetCode_Weekly_282_No4 {

    public int minimumFinishTime(int[][] tires, int changeTime, int numLaps) {
        int [] straight = new int[19];
        Arrays.fill(straight, Integer.MAX_VALUE);

        // 오로지 하나의 타이어만 굴렸을 경우의 최소값(핵심 포인트: 2^18 이상이면 절대 straight로 최소값 만들 수 없음! 무조건 중간에 타이어 교체해야함!)
        for(int [] tire : tires) {
            int f = tire[0];
            int r = tire[1];

            int timeSum = 0;
            for(int i = 1; i <= numLaps; i++) {
                int currentTime = f * (int) Math.pow(r, i-1);
                timeSum += currentTime;
                if(timeSum >= Math.pow(2, 18)) break;
                straight[i] = Math.min(straight[i], timeSum);
            }
        }

        int [] dp = new int[numLaps + 1];
        // 여러 타이어 교체하면서 가능한 최소값
        for(int i = 1; i <= numLaps; i++) {
            dp[i] = i < 18 ? straight[i] : Integer.MAX_VALUE;
            for(int j = 1; j < Math.min(18, i / 2 + 1); j++) {
                dp[i] = Math.min(dp[i], dp[i-j] + changeTime + dp[j]);
            }
        }

        return dp[numLaps];
    }
}
