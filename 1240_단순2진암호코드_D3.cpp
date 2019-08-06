// 그림보고 어떻게 암호코드 위치 찾아낼지 생각해야하는 문제!
#include <iostream>
#include <vector>

using namespace std;
const int MAX = 101;

int map[MAX][MAX];
vector<int> codeList;
vector<int> numList;

int code[5][5][5][5] = {0, };

void checkCode(int x, int y) {
    int cnt = 0;

    while(cnt < 8) {

        int numOfZero = 0, numOfOne = 0;
        for(int i = y; i > y-7; i--) {
            if(map[x][i] == 0) {
                if(numOfOne != 0) {
                    codeList.push_back(numOfOne);
                    numOfOne = 0;
                }
                numOfZero += 1;
            } else {
                if(numOfZero != 0) {
                    codeList.push_back(numOfZero);
                    numOfZero = 0;
                }
                numOfOne += 1;
            }
        }

        if(numOfOne != 0) codeList.push_back(numOfOne);
        else codeList.push_back(numOfZero);

        // for(int i = 0; i < codeList.size(); i++) {
        //     cout << codeList[i] << " ";
        // }
        // cout << endl;

        numList.push_back(code[codeList[0]][codeList[1]][codeList[2]][codeList[3]]);

        codeList.clear();

        y -= 7;
        cnt += 1;
    }
}

int main() {

    int T;
    scanf("%d", &T);

    code[1][1][2][3] = 0;
    code[1][2][2][2] = 1;
    code[2][2][1][2] = 2;
    code[1][1][4][1] = 3;
    code[2][3][1][1] = 4;
    code[1][3][2][1] = 5;
    code[4][1][1][1] = 6;
    code[2][1][3][1] = 7;
    code[3][1][2][1] = 8;
    code[2][1][1][3] = 9;

    for(int tc = 1; tc <= T; tc++) {
        int n, m;
        scanf("%d %d", &n, &m);

        numList.clear();
        codeList.clear();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf("%1d", &map[i][j]);
            }
        }

        bool flag = false;
        for(int i = 0; i < n; i++) {
            for(int j = m-1; j >= 0; j--) {
                if(map[i][j] == 1) {
                    checkCode(i, j);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }

        int len = numList.size();
        int total = 0;
        int odd = 0, even = 0;
        for(int i = len-1; i > 0; i--) {
            if(i % 2 == 1) {
                odd += numList[i];
            } else {
                even += numList[i];
            }
        }

        total = odd*3 + even + numList[0];

        // cout << "total: " << total << endl;
        int ans = 0;
        if(total % 10 == 0) {
            for(int i = 0; i < len; i++) {
                ans += numList[i];
            }
        }
        printf("#%d %d\n", tc, ans);

    }

    return 0;
}