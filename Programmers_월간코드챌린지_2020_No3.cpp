#include <bits/stdc++.h>

using namespace std;
const int MAX = 1005;

int triNums[MAX][MAX];

vector<int> solution(int n) {
    int num = 1;
    int sr = 0, er = n-1, sc = 0, ec = n-1;
    int total = n*(n+1) / 2;

    cout << "total: " << total << endl;
    while (num <= total)
    {
        // 1. 아래
        for(int i = sr; i <= er; i++) {
            if(num > total) break;
            triNums[i][sc] = num++;
        }
        sr++;
        sc++;

        // 2. 오른쪽
        for(int i = sc; i <= ec; i++) {
            if(num > total) break;
            triNums[er][i] = num++;
        }
        ec--;
        er--;

        // 3. 대각선 위
        int tmpX = ec, tmpY = ec;
        for(int i = er; i >= sr; i--) {
            if(num > total) break;
            triNums[i][tmpY--] = num++;
        }
        sr++;
        ec--;
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << triNums[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    vector<int> answer;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!triNums[i][j]) answer.push_back(triNums[i][j]);
        }
    }

    return answer;
}

int main(void) {

    memset(triNums, 0, sizeof(triNums));

    solution(1);
    cout << "-------" << endl;
    solution(2);
    cout << "-------" << endl;
    solution(3);
    cout << "-------" << endl;
    solution(4);
    cout << "-------" << endl;
    solution(5);
    cout << "-------" << endl;
    solution(6);

    return 0;
}