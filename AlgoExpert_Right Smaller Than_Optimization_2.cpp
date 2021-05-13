#include <bits/stdc++.h>

using namespace std;

// O(nlog(n)) time | O(n) space(Average), O(n^2) time | O(n) space(Worst)
struct SpecialBst {
    int val;
    int leftSubSize;
    SpecialBst * left;
    SpecialBst * right;

    SpecialBst(int val) {
        this->val = val;
        leftSubSize = 0;
        left = nullptr;
        right = nullptr;
    }

    void insert(int value, int idx, vector<int> & rightSmallerResult, int numSmallerAtInsertTime = 0) {
        if(value < this->val) {
            leftSubSize++;
            if(left == nullptr) {
                left = new SpecialBst(value);
                rightSmallerResult[idx] = numSmallerAtInsertTime;
            } else {
                left->insert(value, idx, rightSmallerResult, numSmallerAtInsertTime);
            }
        } else {
            numSmallerAtInsertTime += leftSubSize;
            if(value > this->val) numSmallerAtInsertTime++;
            if(right == nullptr) {
                right = new SpecialBst(value);
                rightSmallerResult[idx] = numSmallerAtInsertTime;
            } else {
                right->insert(value, idx, rightSmallerResult, numSmallerAtInsertTime);
            }
        }

        return ;
    }

};

vector<int> rightSmallerThan(vector<int> array) {

    if(array.size() == 0) return {};

    int n = array.size();
    int lastIdx = n-1;

    SpecialBst *bst = new SpecialBst(array[lastIdx]);

    vector<int> result(n);

    for(int i = n-2; i >= 0; i--) {
        bst->insert(array[i], i, result);
    }
    
    return result;
}
