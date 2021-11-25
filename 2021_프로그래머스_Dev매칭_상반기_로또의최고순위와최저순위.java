import java.util.HashSet;

public class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = new int[2];

        int winNumCount = 0;
        int zeroNumCount = 0;

        HashSet<Integer> winNums = new HashSet<>();
        for(int num : win_nums) winNums.add(num);
 
        for(int num : lottos) {
            if(winNums.contains(num)) winNumCount++;
            if(num == 0) zeroNumCount++;
        }

        int maxWinRank = (winNumCount+zeroNumCount <= 1 ? 6 : Math.abs(winNumCount + zeroNumCount - 6) + 1);
        int minWinRank = winNumCount <= 1 ? 6 : Math.abs(winNumCount - 6) + 1;

        answer[0] = maxWinRank;
        answer[1] = minWinRank;

        return answer;
    }
}