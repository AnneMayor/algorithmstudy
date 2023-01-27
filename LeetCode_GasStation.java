public class LeetCode_GasStation {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        long totalAmountOfGas = 0L, totalAmountOfCost = 0L;
        for(int gasAmount : gas) {
            totalAmountOfGas += gasAmount;
        }

        for(int costAmount : cost) {
            totalAmountOfCost += costAmount;
        }

        if(totalAmountOfGas - totalAmountOfCost < 0) return -1;

        int ans = 0;
        int n = gas.length;
        int remain = 0;

        for(int index = 0; index < n; index++) {
            remain = remain - cost[index] + gas[index];

            if(remain < 0) {
                ans = index + 1;
                remain = 0;
            }
        }

        return ans;
    }
}