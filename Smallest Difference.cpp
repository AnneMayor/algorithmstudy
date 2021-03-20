#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo);
vector<int> binarySearch(int num, vector<int> array);

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
    vector<int> smallestDistNums;
    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());

    int smallestDiff = INT_MAX;
    for(int num : arrayTwo) {
        vector<int> currentSmallestNums = binarySearch(num, arrayOne);
        int diff = abs(currentSmallestNums[0] - currentSmallestNums[1]);
        if(smallestDiff > diff) {
            smallestDiff = diff;
            smallestDistNums = currentSmallestNums;
        }
    }
  return smallestDistNums;
}

vector<int> binarySearch(int num, vector<int> array) {
    int left = 0, right = array.size()-1;
    int diff = INT_MAX;
    int result = 0;
    while (left <= right)
    {
        int mid = (left+right) / 2;
        int currentDiff = abs(num-array[mid]);
        if(diff > currentDiff) {
            diff = currentDiff;
            result = array[mid];
        }

        if(num > array[mid]) left = mid+1;
        else right = mid-1;
    }

    return {result, num};
}
