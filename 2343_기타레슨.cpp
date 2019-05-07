#include <iostream>
#include <queue>
#define MAX 100

using namespace std;

queue<pair<int, int> > q;
bool isVisited[MAX][MAX];
char map[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int normal, patient;

void bfsN(int x, int y, int size) {

    pair<int, int> p;
    p.first = x;
    p.second = y;

    isVisited[x][y] = true;
    normal += 1;

    q.push(p);

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx < 0 || ny < 0 || nx >= size || ny >= size) continue;

            if(map[x][y] == map[nx][ny]) {
                if(!isVisited[nx][ny]) {
                    isVisited[nx][ny] = true;
                    p.first = nx;
                    p.second = ny;
                    q.push(p);
                }
            }
        }

    }

}

void bfsP(int x, int y, int size) {

    pair<int, int> p;
    p.first = x;
    p.second = y;

    isVisited[x][y] = true;
    patient += 1;

    q.push(p);

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx < 0 || ny < 0 || nx >= size || ny >= size) continue;

            if(map[x][y] == map[nx][ny]) {
                if(!isVisited[nx][ny]) {
                    isVisited[nx][ny] = true;
                    p.first = nx;
                    p.second = ny;
                    q.push(p);
                }
            }

            if(map[x][y] == 'R' || map[x][y] == 'G') {
                if(map[nx][ny] == 'G' || map[nx][ny] == 'R') {
                    if(!isVisited[nx][ny]) {
                        isVisited[nx][ny] = true;
                        p.first = nx;
                        p.second = ny;
                        q.push(p);
                    }
                }
            }

        }

    }

}

void clear(int size) {
    
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            isVisited[i][j] = false;
        }
    }

    while(!q.empty()) {
        q.pop();
    }

}

int main() {

    int n;
    scanf("%d", &n);
    cin.ignore();
    normal = 0;
    patient = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j< n; j++) {
            cin >> map[i][j];
            isVisited[i][j] = false;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!isVisited[i][j]) {
                bfsN(i, j, n);
            }
        }
    }

    clear(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!isVisited[i][j]) {
                bfsP(i, j, n);
            }
        }
    }

    printf("%d %d", normal, patient);

    return 0;
}