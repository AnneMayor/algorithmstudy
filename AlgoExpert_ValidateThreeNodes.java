import java.util.*;

public class AlgoExpert_ValidateThreeNodes {

    // This is an input class. Do not edit.
    static class BST {
        public int value;
        public BST left = null;
        public BST right = null;
    
        public BST(int value) {
          this.value = value;
        }
    }

    // 1st solution: O(h) time | O(h) space(recursive)
    // public boolean validateThreeNodes(BST nodeOne, BST nodeTwo, BST nodeThree) {
    //     if(isDescendant(nodeTwo, nodeOne)) {
    //         return isDescendant(nodeThree, nodeTwo);
    //     }

    //     if(isDescendant(nodeTwo, nodeThree)) {
    //         return isDescendant(nodeOne, nodeTwo);
    //     }

    //     return false;
    // }

    // public boolean isDescendant(BST node, BST target) {
    //     if(node == null) return false;

    //     if(node == target) return true;

    //     return (node.value > target.value ? isDescendant(node.left, target) : isDescendant(node.right, target));
    // }

    // 2nd solution: O(h) time | O(1) space(while loop)
    // public boolean validateThreeNodes(BST nodeOne, BST nodeTwo, BST nodeThree) {
    //     if(isDescendant(nodeTwo, nodeOne)) {
    //         return isDescendant(nodeThree, nodeTwo);
    //     }`

    //     if(isDescendant(nodeTwo, nodeThree)) {
    //         return isDescendant(nodeOne, nodeTwo);
    //     }

    //     return false;
    // }

    // public boolean isDescendant(BST node, BST target) {
    //     while(node != null && node != target) {
    //         node = (node.value > target.value ? node.left : node.right);
    //     }

    //     return node == target;
    // }

    // 3rd solution: O(d) time | O(1) space
    public boolean validateThreeNodes(BST nodeOne, BST nodeTwo, BST nodeThree) {
        
        BST searchOne = nodeOne;
        BST searchTwo = nodeThree;

        while(true) {
            boolean foundOneFromThree = searchTwo == nodeOne;
            boolean foundThreeFromOne = searchOne == nodeThree;
            boolean foundNodeTwo = (searchOne == nodeTwo) || (searchTwo == nodeTwo);
            boolean finishedSearching = (searchOne == null) && (searchTwo == null);

            if(foundOneFromThree || foundThreeFromOne || foundNodeTwo ||finishedSearching) break;

            if(searchOne != null) {
                searchOne = (searchOne.value > nodeTwo.value ? searchOne.left : searchOne.right);
            }

            if(searchTwo != null) {
                searchTwo = (searchTwo.value > nodeTwo.value ? searchTwo.left : searchTwo.right);
            }
        }

        boolean foundNodeFromOther = (searchOne == nodeThree) || (searchTwo == nodeOne);
        boolean foundNodeTwo = (searchOne == nodeTwo) || (searchTwo == nodeTwo);
        if(!foundNodeTwo || foundNodeFromOther) {
            return false;
        }

        return searchForTarget(nodeTwo, (searchOne == nodeTwo ? nodeThree : nodeOne));
    }

    public boolean searchForTarget(BST node, BST target) {

        while(node != null && node != target) {
            node = (node.value > target.value ? node.left : node.right);
        }

        return node == target;
    }

}
