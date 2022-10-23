public class LeetCode_PathSum {

    public boolean hasPathSum(TreeNode root, int targetSum) {
        if(root == null) return false;

        return calculatePathSum(root, 0, targetSum);
    }

    public boolean calculatePathSum(TreeNode node, int currentSum, int targetSum) {
        if(node == null) return false;

        if(node.left == null && node.right == null) return currentSum + node.val == targetSum;
        
        return calculatePathSum(node.left, currentSum + node.val, targetSum) || calculatePathSum(node.right, currentSum + node.val, targetSum);
    }
    
}