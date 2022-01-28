// Time: O(n+m) | Space: O(max(h1, h2)) => Without Stack data structure!(This is the best optimal solution to optimize space complexity.)
public class AlgoExpert_CompareLeafTraversal_Optimization2 {

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
        BinaryTree[] firstLeafTreeLinkedList = connectLeafNode(tree1, null, null);
        BinaryTree[] secondLeafTreeLinkedList = connectLeafNode(tree2, null, null);

        BinaryTree firstLeafHead = firstLeafTreeLinkedList[0];
        BinaryTree secondLeafHead = secondLeafTreeLinkedList[0];

        while(firstLeafHead != null && secondLeafHead != null) {
            if(firstLeafHead.value != secondLeafHead.value) return false;

            firstLeafHead = firstLeafHead.right;
            secondLeafHead = secondLeafHead.right;
        }

        return firstLeafHead == null && secondLeafHead == null;
    }

    public BinaryTree[] connectLeafNode(BinaryTree curretNode, BinaryTree head, BinaryTree previousNode) {
        if(curretNode == null) return new BinaryTree[]{head, previousNode};

        if(isLeafNode(curretNode)) {
            if(previousNode == null) head = curretNode;
            else {
                previousNode.right = curretNode;
            }

            previousNode = curretNode;
        }

        BinaryTree[] nodes = connectLeafNode(curretNode.left, head, previousNode);
        BinaryTree leftHead = nodes[0];
        BinaryTree leftPreviousNode = nodes[1];

        return connectLeafNode(curretNode.right, leftHead, leftPreviousNode);
    }

    public boolean isLeafNode(BinaryTree currentNode) {
        return (currentNode.left == null) && (currentNode.right == null);
    }
}