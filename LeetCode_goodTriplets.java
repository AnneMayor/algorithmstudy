public class LeetCode_goodTriplets {

    class FenwickTree {
        int[] BIT;
        int n;

        public FenwickTree(int n) {
            this.BIT = new int[n+2];
            this.n = n;
        }

        public long sum(int idx) {
            long ans = 0;
            idx++;
            while(idx > 0) {
                ans += BIT[idx];
                idx -= (idx & (-idx));
            }

            return ans;
        }

        public void update(int idx, int value) {
            idx++;
            while(idx < BIT.length) {
                BIT[idx] += value;
                idx += (idx & (-idx));
            }
        }
    }

    public long goodTriplets(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] pos = new int[n];

        FenwickTree fenwickTree = new FenwickTree(n+1);

        for(int i = 0; i < n; i++) {
            pos[nums2[i]] = i;
        }

        long[] left = new long[n];
        long[] right = new long[n];

        for(int i = 0; i < n; i++) {
            int idx = pos[nums1[i]];
            left[i] = fenwickTree.sum(idx-1);
            fenwickTree.update(idx, 1);
        }

        fenwickTree = new FenwickTree(n+1);

        for(int i = n-1; i >= 0; i--) {
            int idx = pos[nums1[i]];
            right[i] = fenwickTree.sum(n+1) - fenwickTree.sum(idx);
            fenwickTree.update(idx, 1);
        }

        long ans = 0;

        for(int i = 0; i < n; i++) {
            ans += left[i] * right[i];
        }

        return ans;
    }
    
}
