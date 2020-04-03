#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAX = 55;

int numOfChar[MAX];

 int main() {

     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

     int n;
     cin >> n;

     memset(numOfChar, 0, sizeof(numOfChar));

     for(int i = 0; i < n; i++) {
         string s;
         cin >> s;
         int len = s.length();
         int exp = 1;
         for(int j = len-1; j >= 0; j--) {
             numOfChar[s.at(j)-'A'] += exp;
             exp*=10;
         }
     }

     sort(numOfChar, numOfChar+MAX, greater<int>());

     long long ans = 0;
     int num = 9;
     for(int i = 0; i < 55; i++) {
         ans += (numOfChar[i]*num--);
     }

     printf("%lld\n", ans);

     return 0;
 }