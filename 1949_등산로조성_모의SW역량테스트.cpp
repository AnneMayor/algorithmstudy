#define Y first
#define X second
#define pii pair<int,int>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
 
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
 
int N, K, ans;
int board[8][8];
int trip[2][8][8];
vector<pii> topPosition;
 
bool isSafe(int y, int x) {
    return (0 <= y && y < N && 0 <= x && x < N);
}
 
void dfs(int y, int x, int cnt, int used) {
     
    if (cnt > ans) {
        ans = max(ans,cnt);
    }
 
    for (int dir = 0; dir < 4; ++dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
 
        if (isSafe(ny,nx) && !trip[used][ny][nx]) {
             
            if ((board[ny][nx] >= board[y][x]) && used) {
                for (int k = 1; k <= K; ++k) {
                    if ((board[ny][nx] - k < board[y][x]) && !trip[0][ny][nx]) {
                        trip[0][ny][nx] = 1;
                        int before_height = board[ny][nx];
                        board[ny][nx] = max(0, board[ny][nx]-k);
                        dfs(ny,nx,cnt+1,0);
                        board[ny][nx] = before_height;
                        trip[0][ny][nx] = 0;
                    }
                }
            }
            else if (board[ny][nx] < board[y][x]) {
                trip[used][ny][nx] = 1;
                dfs(ny,nx,cnt+1,used);
                trip[used][ny][nx] = 0;
            }
        }
    }
}
 
void solve() {
    for (int i = 0; i < topPosition.size(); ++i) {
        pii now = topPosition[i];
        trip[1][now.Y][now.X] = 1;
        dfs(now.Y,now.X,1,1);
        trip[1][now.Y][now.X] = 0;
    }
}
 
int main(void) {
 
    ios::sync_with_stdio(0);
    cin.tie(NULL);  cout.tie(NULL);
 
    int t;
    cin >> t;
 
    for (int test_case = 1; test_case <= t; ++test_case) {
 
        topPosition.clear();
        memset(board,0x0,sizeof(board));
        memset(trip,0x0,sizeof(trip));
 
        ans = -1;
        cin >> N >> K;
 
        int top_height = -1;
        for (int i = 0; i < N; ++i)
        for (int x,j = 0; j < N; ++j) {
            cin >> x;
            top_height = max(x,top_height);
            board[i][j] = x;
        }
 
        for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (board[i][j] == top_height) 
                topPosition.push_back(make_pair(i,j));
                 
        solve();
        cout << "#" << test_case << " " << ans << "\n";
    }
 
    return 0;
}