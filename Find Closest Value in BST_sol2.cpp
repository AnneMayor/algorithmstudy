#include <cmath>

using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target);
int findClosestValueInBstHelper(BST *tree, int target, int closest);

/* for, while loop way */
// Average: O(log(N)) time | O(1) space
// Worst: O(N) time | O(1) space
int findClosestValueInBst(BST *tree, int target) {
  return findClosestValueInBstHelper(tree, target, tree->value);
}

int findClosestValueInBstHelper(BST *tree, int target, int closest) {
    while (tree != nullptr)
    {
        if(abs(target - closest) > abs(target - tree->value))
            closest = tree->value;

        if(target > tree->value)
            tree = tree->right;
        else if(target < tree->value)
            tree = tree->left;
        else
            break;
    }
    
    return closest;
}