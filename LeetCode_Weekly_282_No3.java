public class LeetCode_Weekly_282_No3 {
    public long minimumTime(int[] time, int totalTrips) {
        
        long lowestTime = 1L;
        // 와 이거 진짜...놀랍다 정말 와...또 하나 배워가네...신기방기...저 숫자 범위 때문에 계속 케이스 하나에서 걸리더라...이거 알아내는 데 정말 쉽지 않았음...ㅠㅠ
        long highestTime = 100_000_000_000_000L;
        while(lowestTime<=highestTime)
        {
            long mid = (lowestTime + highestTime) /2;
            
            if(isAvailable(mid, totalTrips, time))
                highestTime = mid - 1;
            else
                lowestTime = mid + 1;
        }
        return lowestTime;
    }

    public boolean isAvailable(long time, int totalTrips, int[] timeTaken) {
        
        long totalCount = 0L;

        for(int t : timeTaken) {
            totalCount += time / t;
        }

        return (totalCount >= totalTrips ? true : false);
    }
}
