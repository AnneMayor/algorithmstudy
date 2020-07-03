#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 20;

int numArr[MAX];
vector<int> ansList;

void findAns(int n, int k, int start) {
    if(n <= 0) return ;
    int first = numArr[n-1];
    int second = numArr[n-1] + numArr[n-2];
    int third = numArr[n];

    if(n >= 1 && (start < k && k <= start+first)) {
        ansList.push_back(1);
        findAns(n-1, k, start);
    }else if((n >= 2) && (start+first < k) && (start+second >= k)) {
        ansList.push_back(2);
        findAns(n-2, k, start+first);
    }else if(n >= 3 && (start+second < k && start+third >= k)) {
        ansList.push_back(3);
        findAns(n-3, k, start+second);
    }

    return ;
}

int main()
{

    int n, k;
    scanf("%d %d", &n, &k);

    memset(numArr, 0, sizeof(numArr));
    ansList.clear();

    numArr[0] = 1, numArr[1] = 1, numArr[2] = 2, numArr[3] = 4;
    for (int i = 4; i <= n; i++)
    {
        numArr[i] = numArr[i - 1] + numArr[i - 2] + numArr[i - 3];
    }

    findAns(n, k, 0);

    int lenOfAns = ansList.size();
    if(numArr[n] < k) {
        printf("-1\n");
    } else {
        for(int i = 0; i < lenOfAns; i++) {
            printf("%d", ansList[i]);
            if(i < lenOfAns-1) printf("+");
        }
        printf("\n");
    }

    return 0;
}