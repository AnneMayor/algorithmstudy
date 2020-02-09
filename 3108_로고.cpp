#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
#define N 500
#define INF 987654321
using namespace std;

typedef pair<int, int> node;

int n,ans;
int x1,y1,x2,y2;
bool is_startPoint;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

vector<node> s;

void makeRectangle(int xx1,int yy1,int xx2,int yy2){
    // 세로선 체크
    for(int i=xx1; i<xx2; i++){
        // 왼쪽 선
        map[i][yy1] |= (1<<2);
        map[i+1][yy1] |= (1<<0);
        
        // 오른쪽 선
        map[i][yy2] |= (1<<2);
        map[i+1][yy2] |= (1<<0);
    }
    
    // 가로선 체크
    for(int j=yy1; j<yy2; j++){
        // 위쪽 선
        map[xx1][j] |= (1<<1);
        map[xx1][j+1] |= (1<<3);
        
        // 아래쪽 선
        map[xx2][j] |= (1<<1);
        map[xx2][j+1] |= (1<<3);
    }
}

void bfs(int r,int c){
    queue<node> q;
    q.push(node(r,c));
    visited[r][c] = true;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // 스타트 포인트
        if(x == N && y == N)
            is_startPoint = true;
        
        for(int i=0; i<4; i++){
            if(map[x][y] & (1<<i)){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(!visited[nx][ny]){
                    q.push(node(nx,ny));
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> y1 >> x1 >> y2 >> x2;
        makeRectangle(N+x1,N+y1,N+x2,N+y2);
        
        s.push_back(node(N+x1,N+y1));
    }
    
    memset(visited, false, sizeof(visited));
    ans = 0;
    
    // 한 붓 그리기
    for(int i=0; i<s.size(); i++){
        int x = s[i].first;
        int y = s[i].second;
        
        if(!visited[x][y]){
            is_startPoint = false;
            bfs(x,y);
            
            // 한 붓 그리기 도중 로봇의 시작점을 만나지 않았다면
            if(!is_startPoint)
                ans++;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}