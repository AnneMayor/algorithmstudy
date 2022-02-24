import java.util.Collections;
import java.util.PriorityQueue;

public class LeetCode_MinimumDeviation {
    public int minimumDeviation(int[] nums) {
        int minNum = Integer.MAX_VALUE;

        int n = nums.length;

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 1) nums[i] *= 2;
            if(minNum > nums[i]) minNum = nums[i];
            pq.add(nums[i]);
        }

        int diff = Integer.MAX_VALUE;

        while(pq.peek() % 2 == 0) {
            int maxVal = pq.poll();
            diff = Math.min(diff, maxVal - minNum);
            pq.add(maxVal / 2);
            minNum = Math.min(minNum, maxVal / 2);
        }

        return Math.min(diff, pq.peek() - minNum);
    }
}
