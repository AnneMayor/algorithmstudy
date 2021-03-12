#include <cmath>
#include <float.h>

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
int findClosedValueInBstHelper(BST *tree, int target, int closest);

/* Recursive way */
// Average: O(logN) time | O(N) space
// Worst: O(N) time | O(N) space

int findClosestValueInBst(BST *tree, int target) {
  return findClosedValueInBstHelper(tree, target, tree->value);
}

int findClosedValueInBstHelper(BST *tree, int target, int closest) {
    if(tree == nullptr) 
        return closest;

    if(abs(target - closest) > abs(target-tree->value))
        closest = tree->value;

    if(target > tree->value) {
        return findClosedValueInBstHelper(tree->right, target, closest);
    } else if(target < tree->value) {
        return findClosedValueInBstHelper(tree->left, target, closest);
    }

    return closest;
}