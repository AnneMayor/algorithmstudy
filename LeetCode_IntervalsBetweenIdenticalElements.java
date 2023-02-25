public class Solution {
    public long[] getDistances(int[] arr) {

        int n = arr.length;

        long[] res = new long[n];

        Map<Integer, Long> leftSumMap = new HashMap<>();
        Map<Integer, Long> leftCountMap = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int num = arr[i];

            res[i] += (long)(i * leftCountMap.getOrDefault(num, 0l)) - leftSumMap.getOrDefault(num, 0l);
            leftSumMap.put(num, leftSumMap.getOrDefault(num, 0l) + i);
            leftCountMap.put(num, leftCountMap.getOrDefault(num, 0l) + 1);
        }

        Map<Integer, Long> rightSumMap = new HashMap<>();
        Map<Integer, Long> rightCountMap = new HashMap<>();

        for (int i = n - 1; i >= 0; i--) {
            int num = arr[i];

            res[i] += (long)((n - 1 - i) * rightCountMap.getOrDefault(num, 0l)) - rightSumMap.getOrDefault(num, 0l);
            rightSumMap.put(num, rightSumMap.getOrDefault(num, 0l) + n - 1 - i);
            rightCountMap.put(num, rightCountMap.getOrDefault(num, 0l) + 1);
        }

        return res;
    }
}