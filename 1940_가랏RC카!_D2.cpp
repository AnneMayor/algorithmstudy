#include <iostream>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);

        int dir[n], speed[n];
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &dir[i], &speed[i]);
        }

        int curSpeed = 0;
        int distance = 0;

        for(int i = 0; i < n; i++) {
            if(dir[i] == 1) {
                curSpeed += speed[i];
                distance += curSpeed;
            } else if(dir[i] == 2) {
                if(curSpeed - speed[i] <= 0) {
                    curSpeed = 0;
                } else {
                    curSpeed -= speed[i];
                    distance += curSpeed;
                }
            } else {
                distance += curSpeed;
            }
        }

        printf("#%d %d\n", t, distance);
    }

    return 0;
}