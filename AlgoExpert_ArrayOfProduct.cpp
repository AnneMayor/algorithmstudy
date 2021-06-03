#include <bits/stdc++.h>

using namespace std;

vector<int> arrayOfProducts(vector<int> array) {
    int n = array.size();
    int leftProductArr[n]; int rightProductArr[n];
    for(int i = 0; i < n; i++) leftProductArr[i] = 1;
    for(int i = 0; i < n; i++) rightProductArr[i] = 1;

    int midProduct = 1;
    for(int i = 1; i < n; i++) {
        midProduct *= array[i-1];
        leftProductArr[i] = midProduct;
    }

    midProduct = 1;
    for(int i = n-1; i >= 1; i--) {
        midProduct *= array[i];
        rightProductArr[i-1] = midProduct;
    }

    vector<int> result;
    for(int i = 0; i < n; i++) {
        result.push_back(leftProductArr[i]*rightProductArr[i]);
    }

    return result;
}
