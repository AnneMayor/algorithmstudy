package main;

import java.util.Arrays;
import java.util.PriorityQueue;

public class Solution {
    public static int solve_withPriorityQueue(int[][] intervals) {

        Arrays.sort(intervals, (prev, next) -> prev[0] - next[0]);

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int ans = 0;
        for(int [] interval : intervals) {
            System.out.println("start: " + interval[0]);
            if(pq.isEmpty()) {
                ans++;
                pq.add(interval[1]);
            } else {
                int nextStartTime = interval[0];
                int prevFinishTime = pq.peek();

                if(prevFinishTime <= nextStartTime) {
                    pq.poll();
                    pq.add(interval[1]);
                } else {
                    pq.add(interval[1]);
                    ans++;
                }
            }
        }

        return ans;
    }

    public static long solve_withoutPriorityQueue(int[][] intervals) {
        long ans = 0;

        int n = intervals.length;
        int[] start = new int[n];
        int[] end = new int[n];

        for(int i = 0; i < n; i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }

        Arrays.sort(start);
        Arrays.sort(end);

        int startIndex = 1, endIndex = 0, currentCount = 1;
        while ((startIndex < n) && (endIndex < n)) {
            if (start[startIndex] < end[endIndex]) {
                startIndex++;
                currentCount++;
            } else {
                endIndex++;
                currentCount--;
            }

//            System.out.println("current: " + currentCount);
            ans = Math.max(ans, currentCount);
        }

        return ans;
    }

    public static void main(String...args) {
        int[][] intervals1 ={{0,30},{5,10},{15,20}};
        int[][] intervals2 ={{7,10},{2,4}};
        System.out.println(solve_withoutPriorityQueue(intervals1));
        System.out.println(solve_withPriorityQueue(intervals2));
    }
}
