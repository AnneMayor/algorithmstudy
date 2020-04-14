#include <iostream>

using namespace std;
const int MAX = 1005;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);

        double total = 0;
        double scores[MAX];
        for(int i = 0; i < n; i++) {
            int score;
            scanf("%d", &score);
            scores[i] = score;
            total += score;
        }

        double average = total / n;
        int cntOfStudent = 0;
        for(int i = 0 ; i < n; i++) {
            if(average < scores[i]) cntOfStudent++;
        }

        double ans = ((double) cntOfStudent / (double) n) * 100;
        char signalP = '%';
        printf("%.3lf%c\n", ans, signalP);
    }

    return 0;
}