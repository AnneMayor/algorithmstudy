#include <bits/stdc++.h>

using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

bool isDescendant(BST *node, BST *target);
bool searchForTarget(BST *node, BST *target);

// 1st solution: O(h) time | O(h) space complexity
// bool validateThreeNodes(BST *nodeOne, BST *nodeTwo, BST *nodeThree) {
//     if(isDescendant(nodeOne, nodeTwo)) {
//         return isDescendant(nodeTwo, nodeThree);
//     }

//     if(isDescendant(nodeThree, nodeTwo)) {
//         return isDescendant(nodeTwo, nodeOne);
//     }

//     return false;
// }

// bool isDescendant(BST *node, BST *target) {
//     if(node == nullptr) return false;
//     if(node == target) return true;

//     node = (node->value > target->value ? node->left : node->right);

//     return isDescendant(node, target);
// }

// 2nd solution: O(h) time | O(1) space complexity
// bool validateThreeNodes(BST *nodeOne, BST *nodeTwo, BST *nodeThree) {
//     if(isDescendant(nodeOne, nodeTwo)) {
//         return isDescendant(nodeTwo, nodeThree);
//     }

//     if(isDescendant(nodeThree, nodeTwo)) {
//         return isDescendant(nodeTwo, nodeOne);
//     }

//     return false;
// }

// bool isDescendant(BST *node, BST *target) {
//     while (node != nullptr && node != target)
//     {
//         node = (node->value > target->value ? node->left : node->right);
//     }
    
//     return node == target;
// }

bool validateThreeNodes(BST *nodeOne, BST *nodeTwo, BST *nodeThree) {

    BST *searchOne = nodeOne;
    BST *searchTwo = nodeThree;
    
    while (true)
    {
        bool foundOneFromThree = searchOne == nodeThree;
        bool foundThreeFromOne = searchTwo == nodeOne;
        bool foundNodeTow = (searchOne == nodeTwo) || (searchTwo == nodeTwo);
        bool finishedSearching = (searchOne == nullptr) && (searchTwo == nullptr);

        if(finishedSearching || foundNodeTow || foundOneFromThree || foundThreeFromOne) break;

        if(searchOne != nullptr) {
            searchOne = searchOne->value > nodeTwo->value ? searchOne->left : searchOne->right;
        }

        if(searchTwo != nullptr) {
            searchTwo = searchTwo->value > nodeTwo->value ? searchTwo->left : searchTwo->right;
        }
    }

    bool isFoundNodeTwo = (searchOne == nodeTwo) || (searchTwo == nodeTwo);
    bool foundNodeFromOther = (searchOne == nodeThree) || (searchTwo == nodeOne);

    if(!isFoundNodeTwo || foundNodeFromOther) return false;

    return searchForTarget(nodeTwo, (searchOne == nodeTwo ? nodeThree : nodeOne));
}

bool searchForTarget(BST *node, BST *target) {
    while (node != nullptr && node != target)
    {
        node = (node->value > target->value ? node->left : node->right);
    }
    
    return node == target;
}