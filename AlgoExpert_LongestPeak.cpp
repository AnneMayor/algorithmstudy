#include <bits/stdc++.h>

using namespace std;

int longestPeak(vector<int> array) {

    int ans = 0;

    int startIdx = 1;
    int n = array.size();

    while (startIdx < n-1)
    {
        // 1. Find a peak
        if(array[startIdx-1] < array[startIdx] && array[startIdx] > array[startIdx+1]) {
            // 2. expand both of the sides(left, right)
            int leftIdx = startIdx, rightIdx = startIdx;
            int start = startIdx;
            while(start >= 1) {
                if(array[start] <= array[start-1]) {
                    leftIdx = start;
                    break;
                }
                start--;
            }
            leftIdx = start;

            start = startIdx;
            while (start < n-1)
            {
                if(array[start] <= array[start+1]) {
                    rightIdx = start;
                    startIdx = rightIdx;
                    break;
                }
                start++;
            }
            rightIdx = start;

            int totalLength = rightIdx - leftIdx + 1;
            if(totalLength >= 3) ans = max(ans, totalLength);
        }
        startIdx++;
    }

    return ans;
}