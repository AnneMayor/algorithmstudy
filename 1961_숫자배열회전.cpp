#include <iostream>
#include <string>
#define MAX 7

using namespace std;


string ansMap[MAX][3];
int tempMap[MAX][MAX];

void setDefault(int size) {

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < 3; j++) {
            ansMap[i][j] = "0";
        }
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            tempMap[i][j] = 0;
        }
    }

}

int main() {

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);

        int map[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        setDefault(n);

        for(int cnt = 0; cnt < 3; cnt++) {
            // 90도 회전
            int len = n / 2;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < len; j++) {
                    int temp = map[j][i];
                    map[j][i] = map[n-1-j][i];
                    map[n-1-j][i] = temp;
                }
            }

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    tempMap[j][i] = map[i][j];
                }
            }

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    map[i][j] = tempMap[i][j];
                }
                
            }

            // 2차원 배열값 채우기
            for(int i = 0; i < n; i++) {
                string ans = "";
                for(int j = 0; j < n; j++) {
                    ans.append(to_string(tempMap[i][j]));
                }
                ansMap[i][cnt] = ans;
            }

        }

        printf("#%d\n", t);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                cout << ansMap[i][j] << " ";
            }
            printf("\n");
        }
    }

    return 0;
}