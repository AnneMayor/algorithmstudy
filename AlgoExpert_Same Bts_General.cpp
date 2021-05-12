#include <bits/stdc++.h>

using namespace std;

vector<int> getSmaller(vector<int>);
vector<int> getBiggerOrEqual(vector<int>);

// O(N^2) space | O(N^2) time complexity
bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {

    if(arrayOne.size() != arrayTwo.size())
        return false;

    if(arrayOne.size() == 0 && arrayTwo.size() == 0)
        return true;

    if(arrayOne[0] != arrayTwo[0])
        return false;

    vector<int> smallerOne = getSmaller(arrayOne);
    vector<int> smallerTwo = getSmaller(arrayTwo);
    vector<int> biggerOrEqualOne = getBiggerOrEqual(arrayOne);
    vector<int> biggerOrEqualTwo = getBiggerOrEqual(arrayTwo);

    return sameBsts(smallerOne, smallerTwo) && sameBsts(biggerOrEqualOne, biggerOrEqualTwo);
}

vector<int> getSmaller(vector<int> array) {
    vector<int> smaller;
    int n = array.size();
    for(int i = 1; i < n; i++) {
        if(array[i] < array[0]) smaller.push_back(array[i]);
    }

    return smaller;
}

vector<int> getBiggerOrEqual(vector<int> array) {
    vector<int> bigger;
    int n = array.size();
    for(int i = 1; i < n; i++) {
        if(array[i] >= array[0]) bigger.push_back(array[i]);
    }

    return bigger;
}