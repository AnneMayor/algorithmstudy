import java.util.List;

public class Solution {
    private final int MODULO = 1000000007;

    public int maxProduct(TreeNode root) {
        List<Long> sums = new ArrayList();

        long total = helper(root, sums);

        System.out.println("total: " + total);

        long maxProduct = 0;
        for(long sum : sums) {
            maxProduct = Math.max(maxProduct, sum * (total - sum));
        }

        return (int) (maxProduct % MODULO);
    }

    public long helper(TreeNode node, List<Long> sums) {
        if (node == null) return 0;

        long left = helper(node.left, sums);
        long right = helper(node.right, sums);
        long sum = left + right + node.val;
        sums.add(sum);
        return sum;
    }
}