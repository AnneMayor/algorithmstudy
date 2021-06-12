import java.util.function.Function;


public class AlgoExpert_Iterative_In_order_Traversal {
    public static void iterativeInOrderTraversal(BinaryTree tree, Function<BinaryTree, Void> callback) {
        BinaryTree parent = null;
        BinaryTree current = tree;
        BinaryTree next = null;
        while(current != null) {
            if(parent == null || parent == current.parent) {
                if(current.left != null) {
                    next = current.left;
                } else {
                    callback.apply(current);
                    next = (current.right == null ? current.parent : current.right);
                }
            } else if(parent == current.left) {
                callback.apply(current);
                next = (current.right == null ? current.parent : current.right);
            } else {
                next = current.parent;
            }
            parent = current;
            current = next;
        }

    }
  
    static class BinaryTree {
      public int value;
      public BinaryTree left;
      public BinaryTree right;
      public BinaryTree parent;
  
      public BinaryTree(int value) {
        this.value = value;
      }
  
      public BinaryTree(int value, BinaryTree parent) {
        this.value = value;
        this.parent = parent;
      }
    }
}
