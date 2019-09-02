#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int MAX = 4e5;

vector<int> numList;

int main()
{

    char num[MAX];
    scanf("%s", num);

    int len = strlen(num);
    for(int i = len-1; i >= 0; i--)
    {
        int tmp = num[i] - '0';

        for(int i = 0; i < 3; i++) {
            numList.push_back(tmp & 1);
            tmp >>= 1;
        }

    }

    int startIdx = -1;
    int endIdx = numList.size()-1;
    for(int i = endIdx; i >= 0; i--) {
        if(numList[i]) {
            startIdx = i;
            break;
        }
    }

    for(int i = startIdx; i >= 0; i--) {
        printf("%d", numList[i]);
    }

    if(startIdx == -1) {
        printf("%d", numList[startIdx]);
    }

    printf("\n");

    return 0;
}