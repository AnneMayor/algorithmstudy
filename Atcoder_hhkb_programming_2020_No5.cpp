#include <bits/stdc++.h>

#define ll long long

using namespace std;
const int MAX = 2005;
ll modNum = 1000000007;

class mint {
public:
  long long x;
  mint(long long x=0) : x((x%modNum+modNum)%modNum) {}
  mint operator-() const {
    return mint(-x);
  }
  mint& operator+=(const mint& a) {
    if ((x += a.x) >= modNum) x -= modNum;
    return *this;
  }
  mint& operator-=(const mint& a) {
    if ((x += modNum-a.x) >= modNum) x -= modNum;
    return *this;
  }
  mint& operator*=(const  mint& a) {
    (x *= a.x) %= modNum;
    return *this;
  }
  mint operator+(const mint& a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint& a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint& a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  // for prime mod
  mint inv() const {
    return pow(modNum-2);
  }
  mint& operator/=(const mint& a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint& a) const {
    mint res(*this);
    return res/=a;
  }
};

int main(void) {

    int h, w;
    scanf("%d %d", &h, &w);

    char board[MAX][MAX];

    for(int i = 0; i < h; i++) {
        scanf("%s", board[i]);   
    }

    int latCnt[h+1][w+1], lonCnt[h+1][w+1];
    memset(latCnt, 0, sizeof(latCnt));
    memset(lonCnt, 0, sizeof(lonCnt));

    // 1. 가로 .숫자 찾기
    for(int i = 0; i < h; i++) {
        int left = -1;
        for(int j = 0; j < w+1; j++) {
            if(j == w || board[i][j] == '#') {
                if(left != -1) {
                    for(int k = left; k < j; k++) {
                        latCnt[i][k] = j-left;   
                    }
                    left = -1;
                }
            } else {
                if(left == -1) left = j;
            }
        }
    }

    // for(int i = 0; i < h; i++) {
    //     for(int j = 0; j < w; j++) {
    //         cout << latCnt[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // 2. 세로 .숫자 찾기
    for(int i = 0; i < w; i++) {
        int up = -1;
        for(int j = 0; j < h+1; j++) {
            if(j == h || board[j][i] == '#') {
                if(up != -1) {
                    for(int k = up; k < j; k++) {
                        lonCnt[k][i] = j - up;
                    }
                    up = -1;
                }
            } else {
                if(up == -1) up = j;
            }
        }
    }

    // for(int i = 0; i < h; i++) {
    //     for(int j = 0; j < w; j++) {
    //         cout << lonCnt[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // 3. 모든 경우의 수에서 불 안켜는 경우의 수 빼기
    mint numOfLight = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(board[i][j] == '.') numOfLight.x++;
        }
    }
    mint two = 2;
    mint all = two.pow(numOfLight.x)*numOfLight;
    mint ans = all;
    // cout << "all: " << all << endl;
    mint numOfNonLight[h*w+1];
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(board[i][j] == '.') {
                mint cntOfNoLight = latCnt[i][j] + lonCnt[i][j] - 1;
                numOfNonLight[numOfLight.x-cntOfNoLight.x] += 1;
            }
        }
    }
    mint twoDigit = 1;
    for(int i = 0; i <= h*w; i++) {
        // cout << numOfNonLight[i] << endl;
        ans -= numOfNonLight[i]*twoDigit;
        twoDigit *= 2;
    }

    printf("%lld\n", ans.x);

    return 0;
}