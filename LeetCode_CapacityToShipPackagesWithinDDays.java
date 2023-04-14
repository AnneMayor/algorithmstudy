public class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int minWeight = Integer.MIN_VALUE;
        int maxWeight = 0;

        for (int weight : weights) {
            minWeight = Math.max(minWeight, weight);
            maxWeight += weight;
        }

        while (minWeight <= maxWeight) {
            int mid = (minWeight + maxWeight) / 2;

            System.out.println("mid: " + mid);

            if (isShippable(mid, days, weights)) {
                maxWeight = mid - 1;
            } else {
                minWeight = mid + 1;
            }
        }

        return minWeight;
    }

    public boolean isShippable(int capacity, int days, int [] weights) {
        int res = 1;

        int currentWeight = 0;

        for (int weight : weights) {
            currentWeight += weight;

            if (currentWeight > capacity) {
                currentWeight = weight;
                res++;
            }
        }

        return res <= days;
    }
}