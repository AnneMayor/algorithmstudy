#include <bits/stdc++.h>

using namespace std;

vector<int> rightSmallerThan(vector<int> array) {

    vector<int> result;
    int n = array.size();
    for(int i = 0; i < n; i++) {
        int cntOfSmallerNum = 0;
        for(int j = i+1; j < n; j++) {
            if(array[i] > array[j])
                cntOfSmallerNum++;
        }
        result.push_back(cntOfSmallerNum);
    }
    
    return result;
}
