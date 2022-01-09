public class AlgoExpert_AllKindsOfDepths_Sol3 {

    public static int allKindsOfNodeDepths(BinaryTree root) {
        return allKindsMathHelper(root, 0, 0);
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

    public static int allKindsMathHelper(BinaryTree tree, int depthSum, int depth) {
        if(tree == null) return 0;

        depthSum = depth * (depth + 1) / 2;

        return depthSum + allKindsMathHelper(tree.left, depthSum, depth+1) + allKindsMathHelper(tree.right, depthSum, depth+1); 
    }
}
