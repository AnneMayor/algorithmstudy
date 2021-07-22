#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> wUniv;
vector<int> kUniv;

bool comp(int a, int b) {
    return a > b;
}

int main(void) {

    for(int i = 0; i < 10; i++) {
        int score;
        scanf("%d", &score);
        wUniv.push_back(score);
    }

    for(int i = 0; i < 10; i++) {
        int score;
        scanf("%d", &score);
        kUniv.push_back(score);
    }

    sort(wUniv.begin(), wUniv.end(), comp);
    sort(kUniv.begin(), kUniv.end(), comp);

    int wUnivScore = 0, kUnivScore = 0;
    for(int i = 0; i < 3; i++) {
        wUnivScore += wUniv[i];
    }

    for(int i = 0; i < 3; i++) {
        kUnivScore += kUniv[i];
    }

    printf("%d %d\n", wUnivScore, kUnivScore);

    return 0;
}