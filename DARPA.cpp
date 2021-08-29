#include <iostream>

using namespace std;


double locations[201];
double ans;

int isPossible(double locations[], int n, double gap, int m);

int main(void) {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n, m;
        scanf("%d %d", &n, &m);

        for(int i = 0; i < m; i++) {
            scanf("%lf", &locations[i]);
        }

        double left = 0, right = 240;
        ans = 0;
        for (int it = 0; it < 100; it++)
        {
            double mid = (left + right) / 2;
            if(isPossible(locations, n, mid, m)) {
                left = mid;
                ans = mid;
            } else right = mid;
        }

        printf("%.2f\n", ans);
        
    }

    return 0;
}

 int isPossible(double locations[], int n, double gap, int m) {
     int installed = 0;
     double start = -1;
     for(int i = 0; i < m; i++) {
         if(start <= locations[i]) {
             installed++;
             start = locations[i] + gap;
         }
     }
     
     return installed >= n;
 }