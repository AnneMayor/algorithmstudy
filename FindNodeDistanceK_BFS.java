import java.util.*;

public class FindNodeDistanceK_BFS {
  // This is an input class. Do not edit.
  static class BinaryTree {
    public int value;
    public BinaryTree left = null;
    public BinaryTree right = null;

    public BinaryTree(int value) {
      this.value = value;
    }
  }

  static class Pair<U, V> {
    public final U first;
    public final V second;

    public Pair(U first, V second) {
      this.first = first;
      this.second = second;
    }
  }

  public ArrayList<Integer> findNodesDistanceK(BinaryTree tree, int target, int k) {
    HashMap<Integer, BinaryTree> nodesToParents = new HashMap<>();
    populateNodes(tree, nodesToParents, null);
    BinaryTree targetNode = getNodeFromParents(target, tree, nodesToParents);
    return bfsSearch(targetNode, nodesToParents, k);
  }

  public ArrayList<Integer> bfsSearch(BinaryTree node, HashMap<Integer, BinaryTree> map, int k) {
    Queue<Pair<BinaryTree, Integer> > q = new LinkedList<>();
    q.offer(new Pair<BinaryTree, Integer>(node, 0));

    HashSet<Integer> seen = new HashSet<>();
    seen.add(node.value);

    while(!q.isEmpty()) {
      Pair<BinaryTree, Integer> vals = q.poll();
      BinaryTree currentNode = vals.first;
      int currentDist = vals.second;

      if(currentDist == k) {
        ArrayList<Integer> nodeDistK = new ArrayList<>();

        for(Pair<BinaryTree, Integer> res : q) {
          nodeDistK.add(res.first.value);
        }

        nodeDistK.add(currentNode.value);
        return nodeDistK;
      }

      List<BinaryTree> nextNodes = new ArrayList<>();
      nextNodes.add(currentNode.left);
      nextNodes.add(currentNode.right);
      nextNodes.add(map.get(currentNode.value));

      for(BinaryTree tree : nextNodes) {
        if(tree == null) continue;

        if(seen.contains(tree.value)) continue;

        seen.add(tree.value);
        q.add(new Pair<FindNodeDistanceK_BFS.BinaryTree,Integer>(tree, currentDist + 1));
      }
    }

    return new ArrayList<>();
  }

  public void populateNodes(BinaryTree tree, HashMap<Integer, BinaryTree> map, BinaryTree parent) {
    if(tree != null) {
      map.put(tree.value, parent);
      populateNodes(tree.left, map, tree);
      populateNodes(tree.right, map, tree);
    }
  }

  public BinaryTree getNodeFromParents(int target, BinaryTree tree, HashMap<Integer, BinaryTree> map) {
    if(target == tree.value) {
      return tree;
    }

    BinaryTree nodeParent = map.get(target);
    if(nodeParent.left != null && nodeParent.left.value == target) return nodeParent.left;

    return nodeParent.right;
  }
}
