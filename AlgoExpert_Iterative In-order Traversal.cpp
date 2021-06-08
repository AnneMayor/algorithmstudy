#include <bits/stdc++.h>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;
  BinaryTree *parent;

  BinaryTree(int value, BinaryTree *parent = nullptr);
  void insert(vector<int> values, int i = 0);
};

void iterativeInOrderTraversal(BinaryTree *tree, void (*callback)(BinaryTree *tree)) {
    BinaryTree * previeousNode = nullptr;
    BinaryTree * currentNode = tree;
    BinaryTree * nextNode = nullptr;

    while (currentNode != nullptr)
    {
        if(previeousNode == nullptr || previeousNode == currentNode->parent) {
            if(currentNode->left != nullptr) {
                nextNode = currentNode->left;
            } else {
                (*callback)(currentNode);
                nextNode = (currentNode->right != nullptr ? currentNode->right : currentNode->parent);
            }
        }

        else if(previeousNode == currentNode->left) {
            (*callback)(currentNode);
            nextNode = (currentNode->right != nullptr ? currentNode->right : currentNode->parent);
        }

        else {
            nextNode = currentNode->parent;
        }

        previeousNode = currentNode;
        currentNode = nextNode;
    }
    
    return ;
}