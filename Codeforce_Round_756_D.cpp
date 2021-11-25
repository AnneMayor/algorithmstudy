#include <iostream>

using namespace std;

int main(void) {

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; tc++) {
        int n;
        scanf("%d", &n);

        int root = -1;

        int b[n];
        for(int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            if(num-1 == i) root = num-1;
            b[i] = num-1;
        }

        int p[n];
        for(int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            p[i] = num-1;
        }

        int w[n];
        int q[n];
        w[root] = 0;

        for(int i = 0; i < n; i++) {
            q[p[i]] = i;
        }

        bool isPossible = true;

        for(int i = 0; i < n; i++) {
            if(i != root) {
                if(q[b[i]] > q[i]) isPossible = false;
                else w[i] = q[i] - q[b[i]];
            }
        }
        
        if(isPossible) {
            for(int i = 0; i < n; i++) {
                printf("%d ", w[i]);
            }
            printf("\n");
        } else {
            printf("-1\n");
        }
    }

    return 0;
}