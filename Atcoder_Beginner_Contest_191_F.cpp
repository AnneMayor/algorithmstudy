#include <bits/stdc++.h>

using namespace std;

int getGcd(int a, int b) {
    if(b == 0) return a;
    return getGcd(b, a%b);
}

int main(void) {

    int n;
    scanf("%d", &n);

    vector<int> numList;
    int minNum = INT_MAX;
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        minNum = num < minNum? num : minNum;
        numList.push_back(num);
    }

    map<int, int> d;
    for(int num : numList) {
        for(int i = 1; i*i <= num && i <minNum; i++) {
            if(num % i == 0) {
                d[i] = getGcd(d[i], num);
                if(num/i < minNum) {
                    d[num/i] = getGcd(d[num/i], num);
                }
            }
        }   
    }

    int ans = 1;
    for(auto x : d) {
        if(x.first == x.second) ans++;
    }

    printf("%d\n", ans);

    return 0;
}