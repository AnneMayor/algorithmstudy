import java.util.*;

public class FindNodeDistanceK_DFS {
  // This is an input class. Do not edit.
  static class BinaryTree {
    public int value;
    public BinaryTree left = null;
    public BinaryTree right = null;

    public BinaryTree(int value) {
      this.value = value;
    }
  }

  public ArrayList<Integer> findNodesDistanceK(BinaryTree tree, int target, int k) {
    ArrayList<Integer> answer = new ArrayList<>();
    dfsSearch(answer, tree, k, target);
    return answer;
  }

  public int dfsSearch(ArrayList<Integer> ans, BinaryTree tree, int k, int target) {
      if(tree == null) return -1;

      if(tree.value == target) {
          addSubTreeDistK(tree, 0, k, ans);
          return 1;
      }

      int leftDist = dfsSearch(ans, tree.left, k, target);
      int rightDist = dfsSearch(ans, tree.right, k, target);

      if(leftDist == k || rightDist == k) ans.add(tree.value);

      if(leftDist != -1) {
        addSubTreeDistK(tree.right, leftDist+1, k, ans);
        return leftDist + 1;
      }

      if(rightDist != -1) {
        addSubTreeDistK(tree.left, rightDist+1, k, ans);
        return rightDist + 1;
      }

      return -1;
  }

  public void addSubTreeDistK(BinaryTree node, int dist, int k, ArrayList<Integer> ans) {

    if(node == null) return ;

      if(dist == k) {
          ans.add(node.value);
      } else {
          addSubTreeDistK(node.left, dist+1, k, ans);
          addSubTreeDistK(node.right, dist+1, k, ans);
      }
  }

}
