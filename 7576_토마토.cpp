#include <iostream>
#include <queue>

using namespace std;

class Location {

    private:
        int m;
        int n;
        int h;
        int count;

    public:
        void setM(int n) {
            this->m = n;
        }

        void setN(int n) {
            this->n = n;
        }

        void setH(int n) {
            this->h = n;
        }

        void setCnt(int n) {
            this->count = n;
        }

        int getM() {
            return this->m;
        }

        int getN() {
            return this->n;
        }

        int getH() {
            return this->h;
        }

        int getCnt() {
            return this->count;
        }

};

int m, n;
int map[1005][1005];
bool isVisited[1005][1005];
queue<Location> q;
int ans = 0;

void solve() {

    while(!q.empty()) {

        Location nL = q.front();
        q.pop();

        int nn = nL.getN();
        int nm = nL.getM();
        int cnt = nL.getCnt();

        // 뒤
        if(nn+1 < n && !isVisited[nn+1][nm]) {
            isVisited[nn+1][nm] = true;
            if(map[nn+1][nm] == 1) {
                nL.setN(nn+1);
                nL.setM(nm);
                q.push(nL);
            } else if(map[nn+1][nm] == 0) {
                map[nn+1][nm] = 1;
                nL.setN(nn+1);
                nL.setM(nm);
                nL.setCnt(cnt+1);
                q.push(nL);
            }
        }

        // 앞
        if(nn-1 >= 0 && !isVisited[nn-1][nm]) {
            isVisited[nn-1][nm] = true;
            if(map[nn-1][nm] == 1) {
                nL.setN(nn-1);
                nL.setM(nm);
                q.push(nL);
            } else if(map[nn-1][nm] == 0) {
                map[nn-1][nm] = 1;
                nL.setN(nn-1);
                nL.setM(nm);
                nL.setCnt(cnt+1);
                q.push(nL);
            }
        }

        // 왼쪽
        if(nm-1 >= 0 && !isVisited[nn][nm-1]) {
            isVisited[nn][nm-1] = true;
            if(map[nn][nm-1] == 1) {
                nL.setN(nn);
                nL.setM(nm-1);
                q.push(nL);
            } else if(map[nn][nm-1] == 0) {
                map[nn][nm-1] = 1;
                nL.setN(nn);
                nL.setM(nm-1);
                nL.setCnt(cnt+1);
                q.push(nL);
            }
        }

        // 오른쪽
        if(nm+1 < m && !isVisited[nn][nm+1]) {
            isVisited[nn][nm+1] = true;
            if(map[nn][nm+1] == 1) {
                nL.setN(nn);
                nL.setM(nm+1);
                q.push(nL);
            } else if(map[nn][nm+1] == 0) {
                map[nn][nm+1] = 1;
                nL.setN(nn);
                nL.setM(nm+1);
                nL.setCnt(cnt+1);
                q.push(nL);
            }
        }

        ans = cnt;

    }
    
} 

int main() {

    scanf("%d %d", &m, &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            isVisited[i][j] = false;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    int nm = -1, nn = -1;

    Location l;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 1) {
                nn = i;
                nm = j;
                isVisited[nn][nm] = true;
                l.setN(nn);
                l.setM(nm);
                l.setCnt(0);
                q.push(l);
            }
        }
    }

    int zeroCnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 0) zeroCnt++;
        }
    }

    if(zeroCnt == 0) {
        printf("%d\n", 0);
        return 0;
    }

    solve();

    zeroCnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 0) zeroCnt++;
        }
    }

    if(zeroCnt > 0) {
        printf("%d\n",-1);
        return 0;
    }

    printf("%d\n", ans);

    return 0;
}