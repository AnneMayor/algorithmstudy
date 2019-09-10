#include <iostream>

using namespace std;
const int MAX = 6;

int binggo[MAX][MAX];

void deleteNum(int num) {
    for(int i = 1; i < MAX; i++) {
        for(int j = 1; j < MAX; j++) {
            if(binggo[i][j] == num) {
                binggo[i][j] = -1;
                break;
            }
        }
    }
}

int checkBinggo() {
    int result = 0;

    // 가로 체크
    for (int i = 1; i <= MAX; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= MAX; j++) {
            if(binggo[i][j] == -1) {
                cnt++;
            }
        }
        if(cnt >= 5) result++;
    }
    

    // 세로 체크

    for (int j = 1; j <= MAX; j++)
    {
        int cnt = 0;
        for(int i = 1; i <= MAX; i++) {
            if(binggo[i][j] == -1) {
                cnt++;
            }
        }
        if(cnt >= 5) result++;
    }

    // 대각선 체크
    int x = 1, y = 1;
    int cnt = 0;
    while (x <= 5 && y <= 5)
    {
        if(binggo[x++][y++] == -1) cnt++;
    }

    if(cnt >= 5) result++;

    x = 1, y = 5;
    cnt = 0;
    while (x <= 5 && y >= 1)
    {
        if(binggo[x++][y--] == -1) cnt++;
    }

    if(cnt >= 5) result++;
    
    return result;
}

int main() {

    int deletedNum[MAX][MAX];
    int idxX = -1, idxY = -1;

    for(int i = 1; i < MAX; i++) {
        for(int j = 1; j < MAX; j++) {
            scanf("%d", &binggo[i][j]);
        }
    }

    for(int i = 1; i < MAX; i++) {
        for(int j = 1; j < MAX; j++) {
            scanf("%d", &deletedNum[i][j]);
        }
    }

    bool flag = false;
    for(int i = 1; i < MAX; i++) {
        for(int j = 1; j < MAX; j++) {

            // 빙고판에서 숫자 삭제
            deleteNum(deletedNum[i][j]);

            // 빙고 상태 체크
            if(checkBinggo() >= 3) {
                flag = true;
                idxX = i;
                idxY = j;
                break;
            }

        }

        if(flag) break;
    }

    printf("%d\n", (idxX-1)*5+idxY);

    return 0;
}