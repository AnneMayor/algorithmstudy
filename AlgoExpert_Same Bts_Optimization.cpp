#include <bits/stdc++.h>

using namespace std;

bool areSameBts(vector<int> arrayOne, vector<int> arrayTwo, int rootOneIdx, int rootTwoIdx, int minVal, int maxVal);
int getSmallerIdx(vector<int> array, int rootIdx, int minVal);
int getBiggerOrEqualIdx(vector<int> array, int rootIdx, int maxVal);

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
    return areSameBts(arrayOne, arrayTwo, 0, 0, INT_MIN, INT_MAX);
}

bool areSameBts(vector<int> arrayOne, vector<int> arrayTwo, int rootOneIdx, int rootTwoIdx, int minVal, int maxVal) {
    if(rootOneIdx == -1 || rootTwoIdx == -1)
        return rootOneIdx == rootTwoIdx;

    if(arrayOne[rootOneIdx] != arrayTwo[rootTwoIdx])
        return false;

    int rootOneSmallerIdx = getSmallerIdx(arrayOne, rootOneIdx, minVal);
    int rootTwoSmallerIdx = getSmallerIdx(arrayTwo, rootTwoIdx, minVal);
    int rootOneBiggerOrEqualIdx = getBiggerOrEqualIdx(arrayOne, rootOneIdx, maxVal);
    int rootTwoBiggerOrEqualIdx = getBiggerOrEqualIdx(arrayTwo, rootTwoIdx, maxVal);

    int currentVal = arrayOne[rootOneIdx];

    cout << "currentVal: " << currentVal << " / rootOneSmallerIdx: " << rootOneSmallerIdx << " / rootTwoSmallerIdx: " << rootTwoSmallerIdx << endl;
    cout << "currentVal: " << currentVal << " / rootOneBiggerOrEqualIdx: " << rootOneBiggerOrEqualIdx << " / rootTwoBiggerOrEqualIdx: " << rootTwoBiggerOrEqualIdx << endl;

    bool areSameSmaller = areSameBts(arrayOne, arrayTwo, rootOneSmallerIdx, rootTwoSmallerIdx, minVal, currentVal);
    bool areSameBiggerOrEqual = areSameBts(arrayOne, arrayTwo, rootOneBiggerOrEqualIdx, rootTwoBiggerOrEqualIdx, currentVal, maxVal);


    return areSameSmaller && areSameBiggerOrEqual;
}

int getSmallerIdx(vector<int> array, int rootIdx, int minVal) {
    int n = array.size();
    for(int i = rootIdx + 1; i < n; i++) {
        if(array[i] < array[rootIdx] && array[i] >= minVal)
            return i;
    }

    return -1;
}

int getBiggerOrEqualIdx(vector<int> array, int rootIdx, int maxVal) {
    int n = array.size();
    for(int i = rootIdx + 1; i < n; i++) {
        if(array[i] >= array[rootIdx] && array[i] < maxVal)
            return i;
    }

    return -1;
}
