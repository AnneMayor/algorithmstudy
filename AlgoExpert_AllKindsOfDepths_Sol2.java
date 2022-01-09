import java.util.*;

public class AlgoExpert_AllKindsOfDepths_Sol2 {

    public static int allKindsOfNodeDepths(BinaryTree root) {
        return allKindsOfNodeDepthsHelper(root, 0, 0);
    }

    public static int allKindsOfNodeDepthsHelper(BinaryTree currentNode, int depthSum, int depth) {
        if(currentNode == null) return 0;

        depthSum += depth;

        return depthSum + allKindsOfNodeDepthsHelper(currentNode.left, depthSum, depth+1) + allKindsOfNodeDepthsHelper(currentNode.right, depthSum, depth+1);
    }

    static class BinaryTree {
        int value;
        BinaryTree left;
        BinaryTree right;

        public BinaryTree(int value) {
            this.value = value;
            left = null;
            right = null;
        }
    }

}
