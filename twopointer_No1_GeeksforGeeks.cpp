#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {

    vector<int> input1;
    vector<int> input2;

    input1.push_back(1);
    input1.push_back(4);
    input1.push_back(5);
    input1.push_back(7);

    input2.push_back(10);
    input2.push_back(20);
    input2.push_back(30);
    input2.push_back(40);

    int x = 50;

    sort(input1.begin(), input1.end());
    sort(input2.begin(), input2.end());

    int startIdx1 = 0, endIdx2 = input2.size() - 1;

    int curSum = 0;
    int curDiff = INT_MAX;
    int res1, res2;

    while(startIdx1 < input1.size() && endIdx2 >= 0) {
        int diff = abs(input1[startIdx1] + input2[endIdx2] - x);

        if(diff < curDiff) {
            curDiff = diff;
            curSum = input1[startIdx1] + input2[endIdx2];
            res1 = startIdx1, res2 = endIdx2;
        }

        if(input1[startIdx1] + input2[endIdx2] > x) {
            endIdx2--;
        } else if(input1[startIdx1] + input2[endIdx2] < x) {
            startIdx1++;
        } else break;
    }

    printf("%d %d\n", input1[res1], input2[res2]);

    return 0;
}