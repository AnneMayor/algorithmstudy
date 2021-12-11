#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

    vector<int> input;

    input.push_back(12);
    input.push_back(3);
    input.push_back(4);
    input.push_back(1);
    input.push_back(6);
    input.push_back(9);

    sort(input.begin(), input.end());

    int value = 24;

    vector<int> res;


    bool isPossible = false;


    for(int i = 0; i < input.size() - 1; i++) {
        int third = input[i];
        int start = i+1;
        int end = input.size() - 1;

        while (start < end)
        {
            int first = input[start];
            int second = input[end];

            if(first + second + third == value) {
                res.push_back(first);
                res.push_back(second);
                res.push_back(third);
                start++;
                end--;
                isPossible = true;
            } else if(first + second + third > value) {
                end--;
            } else start++;
        }
    }

    if(isPossible) {
        for(int num : res) printf("%d ", num);
        printf("\n");
    } else {
        printf("Impossible\n");
    }

    return 0;
}