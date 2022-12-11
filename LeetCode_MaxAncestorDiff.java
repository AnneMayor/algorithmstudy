public class LeetCode_MaxAncestorDiff {
    public int maxAncestorDiff(TreeNode root) {

        if(root == null) return 0;
        
        return findMaxAncestorDiff(root, root.val, root.val);
    }

    public int findMaxAncestorDiff(TreeNode node, int curMax, int curMin) {
        if(node == null) return curMax - curMin;

        curMax = Math.max(curMax, node.val);
        curMin = Math.min(curMin, node.val);

        int left = findMaxAncestorDiff(node.left, curMax, curMin);
        int right = findMaxAncestorDiff(node.right, curMax, curMin);

        return Math.max(left, right);
    }
}
