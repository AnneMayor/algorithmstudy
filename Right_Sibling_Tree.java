import java.util.*;

// O(N) time | O(d) space(d: hegith of a tree)
class Right_Sibling_Tree {
  public static BinaryTree rightSiblingTree(BinaryTree root) {
    mutate(root, null, false);
    return root;
  }

  // This is the class of the input root. Do not edit it.
  static class BinaryTree {
    int value;
    BinaryTree left = null;
    BinaryTree right = null;

    public BinaryTree(int value) {
      this.value = value;
    }
  }

  public static void mutate(BinaryTree node, BinaryTree parent, boolean isRightNode) {
      if(node == null) return ;

      BinaryTree left = node.left;
      BinaryTree right = node.right;

      // 1. Go to Left Child
      mutate(left, node, false);

      // 2. Transform the parent node's right child
      if(parent == null) node.right = null;
      else if(!isRightNode) {
          node.right = parent.right;
      } else {
          if(parent.right == null) {
              node.right = null;
          } else {
              node.right = parent.right.left;
          }
      }

      // 3. Go to Right Child of the original parent
      mutate(right, node, true);
  }
}
