#include <iostream>
#include <queue>

using namespace std;

class Pair {

private:
    int x;
    int y;
    int cnt;
    
public:
    Pair(int x, int y, int cnt) {
        this->x = x;
        this->y = y;
        this->cnt = cnt;
    }
    
    int getX() {
        return this->x;
    }
    
    int getY() {
        return this->y;
    }
    
    int getCount() {
        return this->cnt;
    }
    
    void setX(int x) {
        this->x = x;
    }
    
    void setY(int y) {
        this->y = y;
    }
    
    void setCnt(int cnt) {
        this->cnt = cnt;
    }
    
};

int n, m;
int map[101][101];
bool isChecked[101][101];
queue<Pair> q;
int xR[] = {0, 0, -1, 1};
int yR[] = {-1, 1, 0, 0};

int solve(int x, int y) {
    
    Pair p(x, y, 1);
    
    isChecked[x][y] = true;
    
    q.push(p);
    
    while(!q.empty()) {
        
        Pair nP = q.front();
        q.pop();
        int xL = nP.getX();
        int yL = nP.getY();
        int cnt = nP.getCount();
        
        for(int i = 0; i < 4; i++) {
            
            int nx = xL+xR[i];
            int ny = yL+yR[i];
            
            if(map[nx][ny] == 1) {
                if(nx == n-1 && ny == m-1) {
                    return cnt+1;
                }
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                
                if(isChecked[nx][ny] == true) continue;
                isChecked[nx][ny] = true;
                nP.setX(nx);
                nP.setY(ny);
                nP.setCnt(cnt+1);
                q.push(nP);
            }
            
        }
    }
    
    return 0;
    
}


int main() {
    
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            isChecked[i][j] = false;
        }
    }
    
    int ans = solve(0, 0);
    
    printf("%d\n", ans);
    
    return 0;
}
