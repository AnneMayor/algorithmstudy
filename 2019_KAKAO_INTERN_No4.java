public class Solution {

    // Time: O(nlogm) | Space: O(1)
    public int solution(int[] stones, int k) {
        int answer = 0;
        int start = 1, end = 200000000;
        while(start <= end) {
            int mid = (start + end) / 2;

            if(isPossible(mid, stones, k)) {
                answer = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return answer;
    }

    public boolean isPossible(int val, int [] stones, int k) {
        int zeroInterval = 0;
        for(int stone : stones) {
            if(stone < val) {
                zeroInterval++;
            } else {
                zeroInterval = 0;
            }
            if(zeroInterval >= k) {
                return false;
            }
        }
        return true;
    }
}