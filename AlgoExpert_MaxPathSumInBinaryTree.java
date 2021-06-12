import java.util.*;


public class AlgoExpert_MaxPathSumInBinaryTree {

    static class BinaryTree {
        public int value;
        public BinaryTree left;
        public BinaryTree right;

        public BinaryTree(int value) {
            this.value = value;
        }
    }

    public static int maxPathSum(BinaryTree tree) {
        List<Integer> maxPath = findMaxPath(tree);
        return maxPath.get(1);
    }

    public static List<Integer> findMaxPath(BinaryTree tree) {
        if(tree == null) return new ArrayList<Integer>(Arrays.asList(0, Integer.MIN_VALUE));

        List<Integer> leftMaxPath = findMaxPath(tree.left);
        int leftMaxPathSumAsBranch = leftMaxPath.get(0);
        int leftMaxPathSum = leftMaxPath.get(1);

        List<Integer> rightMaxPath = findMaxPath(tree.right);
        int rightMaxPathSumAsBranch = rightMaxPath.get(0);
        int rightMaxPathSum = rightMaxPath.get(1);

        int value = tree.value;
        int maxChildSumAsBranch = Math.max(leftMaxPathSumAsBranch, rightMaxPathSumAsBranch);
        int maxPathSumAsBranch = Math.max(maxChildSumAsBranch+value, value);
        int maxPathSumAsRootNode = Math.max(value+leftMaxPathSumAsBranch+rightMaxPathSumAsBranch, maxPathSumAsBranch);
        int maxPathSum = Math.max(leftMaxPathSum, Math.max(rightMaxPathSum, maxPathSumAsRootNode));

        return new ArrayList<Integer>(Arrays.asList(maxPathSumAsBranch, maxPathSum));
    }
}
