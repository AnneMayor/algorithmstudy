#include <vector>
#include <iostream>

using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

vector<int> branchSums(BinaryTree *root);
void calculateBrachSums(BinaryTree *root, int node, int sum, vector<int> & answer);

vector<int> branchSums(BinaryTree *root) {
    vector<int> answer;
    calculateBrachSums(root, 0, 0, answer);
    return answer;
}

void calculateBrachSums(BinaryTree *root, int node, int sum, vector<int> & answer) {

    if(root == nullptr)
        return ;
	
    node = root->value;
    if(root->left == nullptr && root->right == nullptr) {
        answer.push_back(sum + node);
        return;
    }

    // left
    calculateBrachSums(root->left, node, sum+node, answer);

    // right
    calculateBrachSums(root->right, node, sum+node, answer);

    return ;
}
