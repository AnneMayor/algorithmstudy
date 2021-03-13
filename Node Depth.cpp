using namespace std;

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

int total;

int nodeDepths(BinaryTree *root);
void sumAllNodeDepth(BinaryTree *root, int sum);

int nodeDepths(BinaryTree *root) {
    total = 0;
    sumAllNodeDepth(root, 0);
    return total;
}

void sumAllNodeDepth(BinaryTree *root, int sum) {
    if(root == nullptr) {
        return ; 
    }

    total += sum;
    sumAllNodeDepth(root->left, sum+1);
    sumAllNodeDepth(root->right, sum+1);
    
    return ;
}