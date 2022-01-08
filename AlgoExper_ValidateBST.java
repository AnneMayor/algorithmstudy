import java.util.*;

class AlgoExper_ValidateBST {
  public static boolean validateBst(BST tree) {
    return recursiveSearch(tree, Integer.MIN_VALUE, Integer.MAX_VALUE);
  }

  public static boolean recursiveSearch(BST tree, int minValue, int maxValue) {

    if(tree.value < minValue || tree.value > maxValue) return false;

    if(tree.left != null && !recursiveSearch(tree.left, minValue, tree.value)) return false;

    if(tree.right != null & !recursiveSearch(tree.right, tree.value, maxValue)) return false;

    return true;
  }

  static class BST {
    public int value;
    public BST left;
    public BST right;

    public BST(int value) {
      this.value = value;
    }
  }
}
