import java.util.Stack;


// Time: O(n+m) | Space: O(h1 + h2)
public class AlgoExpert_CompareLeafTraversal_Optimization1 {

    // This is an input class. Do not edit.
    static class BinaryTree {
        public int value;
        public BinaryTree left = null;
        public BinaryTree right = null;

        public BinaryTree(int value) {
            this.value = value;
        }
    }

    public boolean compareLeafTraversal(BinaryTree tree1, BinaryTree tree2) {

        Stack<BinaryTree> firstTreeLeaves = new Stack<>();
        firstTreeLeaves.push(tree1);

        Stack<BinaryTree> secondTreeLeaves = new Stack<>();
        secondTreeLeaves.push(tree2);

        while(!firstTreeLeaves.isEmpty() && !secondTreeLeaves.isEmpty()) {
            BinaryTree firstLeaf = getLeafNode(firstTreeLeaves);
            BinaryTree secondLeaf = getLeafNode(secondTreeLeaves);

            if(firstLeaf.value != secondLeaf.value) return false;
        }


        return firstTreeLeaves.size() == 0 && secondTreeLeaves.size() == 0;
    }

    public BinaryTree getLeafNode(Stack<BinaryTree> tree) {
        BinaryTree currentTree = tree.pop();

        while(!isLeafNode(currentTree)) {
            if(currentTree.right != null) tree.add(currentTree.right);
            if(currentTree.left != null) tree.add(currentTree.left);
            currentTree = tree.pop();
        }

        return currentTree;
    }

    public boolean isLeafNode(BinaryTree currentNode) {
        return (currentNode.left == null) && (currentNode.right == null);
    }
}