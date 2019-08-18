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

int m, n, h;
int map[105][105][105];
bool isVisited[105][105][105];
queue<Location> q;
int ans = 0;

void solve() {

    while(!q.empty()) {

        Location nL = q.front();
        q.pop();

        int nn = nL.getN();
        int nm = nL.getM();
        int nh = nL.getH();
        int cnt = nL.getCnt();

        // 위
        if(nh+1 < h && !isVisited[nn][nm][nh+1]) {
            isVisited[nn][nm][nh+1] = true;
            if(map[nn][nm][nh+1] == 1) {
                nL.setN(nn);
                nL.setM(nm);
                nL.setH(nh+1);
                q.push(nL);
            } else if(map[nn][nm][nh+1] == 0) {
                map[nn][nm][nh+1] = 1;
                nL.setN(nn);
                nL.setM(nm);
                nL.setH(nh+1);
                nL.setCnt(cnt+1);
                q.push(nL);
            }
        }

        // 아래
        if(nh-1 >= 0 && !isVisited[nn][nm][nh-1]) {
            isVisited[nn][nm][nh-1] = true;
            if(map[nn][nm][nh-1] == 1) {
                nL.setN(nn);
                nL.setM(nm);
                nL.setH(nh-1);
                q.push(nL);
            } else if(map[nn][nm][nh-1] == 0) {
                map[nn][nm][nh-1] = 1;
                nL.setN(nn);
                nL.setM(nm);
                nL.setH(nh-1);
                nL.setCnt(cnt+1);
                q.push(nL);
            }
        }

        // 뒤
        if(nn+1 < n && !isVisited[nn+1][nm][nh]) {
            isVisited[nn+1][nm][nh] = true;
            if(map[nn+1][nm][nh] == 1) {
                nL.setN(nn+1);
                nL.setM(nm);
                nL.setH(nh);
                q.push(nL);
            } else if(map[nn+1][nm][nh] == 0) {
                map[nn+1][nm][nh] = 1;
                nL.setN(nn+1);
                nL.setM(nm);
                nL.setH(nh);
                nL.setCnt(cnt+1);
                q.push(nL);
            }
        }

        // 앞
        if(nn-1 >= 0 && !isVisited[nn-1][nm][nh]) {
            isVisited[nn-1][nm][nh] = true;
            if(map[nn-1][nm][nh] == 1) {
                nL.setN(nn-1);
                nL.setM(nm);
                nL.setH(nh);
                q.push(nL);
            } else if(map[nn-1][nm][nh] == 0) {
                map[nn-1][nm][nh] = 1;
                nL.setN(nn-1);
                nL.setM(nm);
                nL.setH(nh);
                nL.setCnt(cnt+1);
                q.push(nL);
            }
        }

        // 왼쪽
        if(nm-1 >= 0 && !isVisited[nn][nm-1][nh]) {
            isVisited[nn][nm-1][nh] = true;
            if(map[nn][nm-1][nh] == 1) {
                nL.setN(nn);
                nL.setM(nm-1);
                nL.setH(nh);
                q.push(nL);
            } else if(map[nn][nm-1][nh] == 0) {
                map[nn][nm-1][nh] = 1;
                nL.setN(nn);
                nL.setM(nm-1);
                nL.setH(nh);
                nL.setCnt(cnt+1);
                q.push(nL);
            }
        }

        // 오른쪽
        if(nm+1 < m && !isVisited[nn][nm+1][nh]) {
            isVisited[nn][nm+1][nh] = true;
            if(map[nn][nm+1][nh] == 1) {
                nL.setN(nn);
                nL.setM(nm+1);
                nL.setH(nh);
                cout << "cnt: " << cnt << endl;
                q.push(nL);
            } else if(map[nn][nm+1][nh] == 0) {
                map[nn][nm+1][nh] = 1;
                nL.setN(nn);
                nL.setM(nm+1);
                nL.setH(nh);
                nL.setCnt(cnt+1);
                q.push(nL);
            }
        }

        ans = cnt;

    }
    
} 

int main() {

    scanf("%d %d %d", &m, &n, &h);

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                isVisited[j][k][i] = false;
            }
        }
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                scanf("%d", &map[j][k][i]);
            }
        }
    }

    int nm = -1, nn = -1, nh = -1;

    Location l;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(map[j][k][i] == 1) {
                    nm = k;
                    nn = j;
                    nh = i;
                    l.setN(nn);
                    l.setM(nm);
                    l.setH(nh);
                    l.setCnt(0);
                    isVisited[nn][nm][nh] = true;
                    q.push(l);
                }
            }
        }
    }

    int zeroCnt = 0;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(map[j][k][i] == 0) zeroCnt++;
            }
        }
    }

    if(zeroCnt == 0) {
        printf("%d\n", 0);
        return 0;
    }

    solve();

    // cout << "-----------------------------------------" << endl;
    // for(int i = 0; i < h; i++) {
    //     for(int j = 0; j < n; j++) {
    //         for(int k = 0; k < m; k++) {
    //             cout << map[j][k][i] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    zeroCnt = 0;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(map[j][k][i] == 0) zeroCnt++;
            }
        }
    }

    if(zeroCnt > 0) {
        printf("%d\n",-1);
        return 0;
    }

    printf("%d\n", ans);

    return 0;
}