#include <vector>
#include <cmath>

using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
};

vector<int> findMaxSum(BinaryTree *tree);

int maxPathSum(BinaryTree tree) {
  vector<int> maxPathSumList = findMaxSum(&tree);
  return maxPathSumList[1];
}

vector<int> findMaxSum(BinaryTree *tree) {
  if(tree == nullptr) return {0, INT_MIN};

  vector<int> leftMaxPath = findMaxSum(tree->left);
  int leftMaxPathAsBranch = leftMaxPath[0];
  int leftMaxPathSum = leftMaxPath[1];

  vector<int> rightMaxPath = findMaxSum(tree->right);
  int rightMaxPathAsBranch = rightMaxPath[0];
  int rightMaxPathSum = rightMaxPath[1];

  int maxChildPathSumAsBranch = max(leftMaxPathAsBranch, rightMaxPathAsBranch);
  // int maxChildPathSum = max(leftMaxPathSum, rightMaxPathSum);

  int value = tree->value;
  int maxPathSumAsBranch = max(maxChildPathSumAsBranch + value, value);
  int maxPathAsRootNode = max(leftMaxPathAsBranch + value + rightMaxPathAsBranch, maxPathSumAsBranch);
  int maxPathSum = max(leftMaxPathSum, max(rightMaxPathSum, maxPathAsRootNode));

  return vector<int>{maxPathSumAsBranch, maxPathSum};
}
