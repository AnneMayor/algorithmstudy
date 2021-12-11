#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

    vector<int> input;
    // input.push_back(0);
    // input.push_back(-1);
    // input.push_back(2);
    // input.push_back(-3);
    // input.push_back(1);

    input.push_back(1);
    input.push_back(-2);
    input.push_back(1);
    input.push_back(0);
    input.push_back(5);

    sort(input.begin(), input.end());
    
    vector<int> res;

    for(int i = 0; i < input.size() - 1; i++) {
        int thirdNum = input[i];
        int start = input[i+1];
        int end = input.size() - 1;

        while (start < end)
        {
            cout << i << " , " << start << " , " << end << endl;
            int first = input[start];
            int second = input[end];

            if((first + second + thirdNum) == 0) {
                res.push_back(input[first]);
                res.push_back(input[end]);
                res.push_back(input[i]);
                start++;
                end--;
            } else if((first + second + thirdNum) > 0) {
                end--;
            } else {
                start++;
            }
        }
    }

    for(int num : res) printf("%d ", num);
    printf("\n");

    return 0;
}