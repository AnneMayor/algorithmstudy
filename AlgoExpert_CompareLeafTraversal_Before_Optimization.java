import java.util.ArrayList;
import java.util.List;

// 14:06
// Q1. 입력값의 데이터 타입이 어떻게 되나요?
// Q2. 균형잡힌 이진 트리인지요?
// Q3. root가 null일 경우가 있나요?
// Q4. root 시작점은 고정인가요?
// Q5. 데이터로 주어지는 BinaryTree의 크기는 어떻게 되는지 궁금합니다
// Q6. 중복으로 주어지는 Node들이 있을 수 있나요?
// Q7. 함수 Call 스택 오버플로우/언더플로우 경우도 고려해야하나요?
// Pre-Order Traversal(Time: O(n+m) | Space: O(n+m) where exactly O((n+1)/2 + (m+1)/2) -> the number of each tree's leaf nodes)
public class AlgoExpert_CompareLeafTraversal_Before_Optimization {

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
        
        List<BinaryTree> firstLeaf = new ArrayList<>();
        List<BinaryTree> secondLeaf = new ArrayList<>();

        getLeafNode(tree1, firstLeaf);
        getLeafNode(tree2, secondLeaf);

        // for(BinaryTree firstTree : firstLeaf) {
        //     System.out.print(firstTree.value + " ");
        // }
        // System.out.println();

        // for(BinaryTree secondTree : secondLeaf) {
        //     System.out.print(secondTree.value + " ");
        // }
        // System.out.println();

        if(firstLeaf.size() != secondLeaf.size()) return false;
        int len = firstLeaf.size();
        for(int i = 0; i < len; i++) {
            if(firstLeaf.get(i).value != secondLeaf.get(i).value) return false;
        }
        
        return true;
    }

    public void getLeafNode(BinaryTree tree, List<BinaryTree> leaves) {

        if(tree == null) return ;

        if(tree.left == null && tree.right == null) {
            leaves.add(tree);
            return ;
        }

        if(tree.left != null) getLeafNode(tree.left, leaves);
        if(tree.right != null) getLeafNode(tree.right, leaves);
    }

}
// 14:32