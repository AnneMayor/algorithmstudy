#include <iostream>

using namespace std;

bool isChecked[10];

void setFalse() {
    for(int i = 1; i < 10; i++) {
        isChecked[i] = false;
    }
}

int main() {

    int T;
    int map[9][9];
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {

        int ans = 1;

        setFalse();
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        // 3*3 검사
        for(int x = 0; x <= 6; x += 3) {
            for(int y = 0; y <= 6; y += 3) {
                
                setFalse();

                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        if(isChecked[map[x+i][y+j]]) {
                            ans = 0;
                            break;
                        } else {
                            isChecked[map[x+i][y+j]] = true;
                        }
                    }
                    if(ans == 0) break;
                }

                if(ans == 0) break;

            }

            if(ans == 0) break;

        }

        if(ans == 0) {
            printf("#%d %d\n", t, ans);
            continue;
        }

        // 행 검사, 열 검사

        for(int x = 0; x < 9; x++) {
            setFalse();
            for(int y = 0; y < 9; y++) {
                if(isChecked[map[x][y]]) {
                    ans = 0;
                    break;
                } else {
                    isChecked[map[x][y]] = true;
                }
            }

            setFalse();
            for(int y = 0; y < 9; y++) {
                if(isChecked[map[y][x]]) {
                    ans = 0;
                    break;
                } else {
                    isChecked[map[y][x]] = true;
                }
            }

            if(ans == 0) break;
        }

        if(ans == 0) {
            printf("#%d %d\n", t, ans);
            continue;
        }

        printf("#%d %d\n", t, ans);

    }

    return 0;
}