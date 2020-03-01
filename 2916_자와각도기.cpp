#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;
const int MAX = 365;

bool isPossible[MAX];
vector<int> degrees;

void checkDegree(int degree, int n) {
    if(degree > 360) degree -= 360;
    
    if(isPossible[degree]) return ;

    isPossible[degree] = true;

    for(int i = 0; i < n; i++) {
        checkDegree(abs(degrees[i]-degree), n);
        checkDegree(degree+degrees[i], n);
    }

    return ;
}

int main() {

    int N, K;
    scanf("%d %d", &N, &K);

    memset(isPossible, false, sizeof(isPossible));

    for(int i = 0; i < N; i++) {
        int deg;
        scanf("%d", &deg);
        degrees.push_back(deg);
    }

    checkDegree(degrees[0], N);

    for(int i = 0; i < K; i++) {
        int degree;
        scanf("%d", &degree);

        if(isPossible[degree]) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}