#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;
const int MAX = 1e5+5;

double value[MAX];
double weight[MAX];
pair<double, int> valuePerWeight[MAX];

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%lf %lf", &weight[i], &value[i]);
        valuePerWeight[i].first = value[i] / weight[i];
        valuePerWeight[i].second = i;
    }

    sort(valuePerWeight, valuePerWeight+n, greater<pair<double, int> >());

    // for(int i = 0; i < n; i++) {
    //     cout << valuePerWeight[i].first << " ";
    // }
    // cout << endl;

    double ans = 0.0;

    for(int i = 0; i < n; i++) {
        if(weight[valuePerWeight[i].second] <= m) {
            ans += value[i];
            m -= weight[valuePerWeight[i].second];
        } else {
            ans += m*valuePerWeight[i].first;
            break;
        }
    }

    printf("%.3f\n", ans);

    return 0;
}