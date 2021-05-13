#include <bits/stdc++.h>

using namespace std;

struct SpecialBst {
    SpecialBst *left;
    SpecialBst *right;
    int value;
    int rootIdx;
    int numSmallerAtInsertTime;
    int leftSubTree;

    SpecialBst(int value, int rootIdx, int numberSmallerAtInsertTime) {
        this->value = value;
        this->rootIdx = rootIdx;
        this->numSmallerAtInsertTime = numberSmallerAtInsertTime;
        leftSubTree = 0;
        left = nullptr;
        right = nullptr;
    }

    void insert(int val, int rootIdx, int numSmallerAtInsertTime = 0) {
        if(val < this->value) {
            leftSubTree++;
            if(left == nullptr) {
                left = new SpecialBst(val, rootIdx, numSmallerAtInsertTime);
            } else {
                left->insert(val, rootIdx, numSmallerAtInsertTime);
            }
        } else {
            numSmallerAtInsertTime += leftSubTree;
            if(val > this->value) numSmallerAtInsertTime++;
            if(right == nullptr) {
                right = new SpecialBst(val, rootIdx, numSmallerAtInsertTime);
            } else {
                right->insert(val, rootIdx, numSmallerAtInsertTime);
            }
        }

        return ;
    }
};

void getRightSmallerArray(SpecialBst * bst, vector<int> & arr);

vector<int> rightSmallerThan(vector<int> array) {

    if(array.size() == 0) return {};

    int n = array.size();
    vector<int> result(n);

    int lastIdx = n-1;
    result[lastIdx] = 0;

    SpecialBst *bst = new SpecialBst(array[lastIdx], lastIdx, 0);

    for(int i = n-2; i >= 0; i--) {
        bst->insert(array[i], i);
    }

    getRightSmallerArray(bst, result);

    return result;
}

void getRightSmallerArray(SpecialBst * bst, vector<int> & arr) {
    if(bst == nullptr) return ;
    arr[bst->rootIdx] = bst->numSmallerAtInsertTime;
    getRightSmallerArray(bst->left, arr);
    getRightSmallerArray(bst->right, arr);
    return ;
}