#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

int main(void) {

    int n, d, k, c;

    scanf("%d %d %d %d", &n, &d, &k, &c);

    vector<int> sushi;
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        sushi.push_back(num);
    }

    deque<int> dq;
    vector<int> have(d+1);
    int type = 0, res = 0;

    for(int i = 0; i < k; i++) {
        dq.push_back(sushi[i]);
        if(!have[sushi[i]]++) {
            type++;
        }
        res = max(res, type);
    }

    for(int i = 0; i < n - 1; i++) {
        dq.pop_front();

        if(!(--have[sushi[i]])) {
            type--;
        }

        dq.push_back(sushi[(i+k) % n]);

        have[sushi[(i + k) % n]]++;
        if (have[sushi[(i+k) %n]] == 1) {
            type++;
        }

        if(have[c] == 0) res = max(res, type+1);
        else res = max(res, type);
    }

    printf("%d\n", res);
    return 0;
}