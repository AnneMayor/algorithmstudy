#include <bits/stdc++.h>

using namespace std;
const int MAX = 1005;

int triangleMap[MAX][MAX];

vector<int> solution(int n) {
    vector<int> answer;
    memset(triangleMap, 0, sizeof(triangleMap));

    int up = 0, down = n-1, left = 0, right = n-1;
    int num = 1;
    int end = n*(n+1) / 2;
    while (true)
    {
        // 아래
        for(int i = up; i <= down; i++) {
            triangleMap[i][left] = num++;
        }
        if(num > end) break;
        up++;
        left++;
        
        // 오른쪽
        for(int i = left; i <= right; i++) {
            triangleMap[down][i] = num++;
        }
        if(num > end) break;
        down--;
        right--;

        int diagonal = right;
        // 대각선
        for(int i = down; i >= up; i--) {
            triangleMap[i][diagonal--] = num++;
        }
        if(num > end) break;
        up++;
        right--;
    }

    // for(int i = 0; i < 5; i++) {
    //     for(int j = 0; j < 5; j++) {
    //         cout << triangleMap[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!triangleMap[i][j]) answer.push_back(triangleMap[i][j]);
        }
    }
    
    return answer;
}