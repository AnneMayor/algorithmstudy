import java.util.*;

public class AlgoExpert_AllKindsOfDepths_Sol1 {
    public static int allKindsOfNodeDepths(BinaryTree root) {
        ArrayList<BinaryTree> nodes = new ArrayList<>();

        nodes.add(root);

        int totalSum = 0;
        // 여기 부분이 되게 인상적!
        while(nodes.size() > 0) {
            BinaryTree curretNode = nodes.remove(nodes.size() - 1);
            if(curretNode == null) continue;
            totalSum += getNodeDepth(curretNode, 0);
            nodes.add(curretNode.left);
            nodes.add(curretNode.right);
        }

        return totalSum;
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

    public static int getNodeDepth(BinaryTree node, int depth) {
        if(node == null) return 0;
        return depth + getNodeDepth(node.left, depth + 1) + getNodeDepth(node.right, depth + 1);
    }
}
