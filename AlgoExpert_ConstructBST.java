import java.util.*;

// 여기서 중요한 포인트는 시간복잡도 & 공간복잡도!
public class AlgoExpert_ConstructBST {
  static class BST {
    public int value;
    public BST left;
    public BST right;

    public BST(int value) {
      this.value = value;
    }

    public BST insert(int value) {
        BST currentNode = this;
        while(true) {
            if(currentNode.value > value) {
                if(currentNode.left == null) {
                    currentNode.left = new BST(value);
                    break;
                }
                else currentNode = currentNode.left;
            } else {
                if(currentNode.right == null) {
                    currentNode.right = new BST(value);
                    break;
                } else currentNode = currentNode.right;
            }
        }
        return this;
    }

    public boolean contains(int value) {
      BST currentNode = this;
      while(true) {
          if(currentNode == null) break;
          if(currentNode.value == value) return true;
          if(currentNode.value > value) currentNode = currentNode.left;
          else currentNode = currentNode.right;
      }
      return false;
    }

    public BST remove(int value) {
        remove(value, null);
        return this;
    }

    public void remove(int value, BST parentNode) {
        BST currentNode = this;
        while(currentNode != null) {
            if(currentNode.value > value) {
                parentNode = currentNode;
                currentNode = currentNode.left;
            } else if(currentNode.value < value) {
                parentNode = currentNode;
                currentNode = currentNode.right;
            } else {
                // remove 연산 수행!
                if(currentNode.left != null && currentNode.right != null) {
                    currentNode.value = currentNode.right.getMinValue();
                    currentNode.right.remove(currentNode.value, currentNode);
                } else if(parentNode == null) {
                    // root node case
                    if(currentNode.left != null) {
                        currentNode.value = currentNode.left.value;
                        currentNode.right = currentNode.left.right;
                        currentNode.left = currentNode.left.left;
                    } else if(currentNode.right != null) {
                        currentNode.value = currentNode.right.value;
                        currentNode.left = currentNode.right.left;
                        currentNode.right = currentNode.right.right;
                    }
                } else if(parentNode.left == currentNode) {
                    parentNode.left = currentNode.left != null ? currentNode.left : currentNode.right;
                } else if(parentNode.right == currentNode) {
                    parentNode.right = currentNode.left != null ? currentNode.left : currentNode.right;
                }

                return ;
            }

        }
    }

    public int getMinValue() {
        if(left == null) return value;
        return left.getMinValue();
    }
  }
}
