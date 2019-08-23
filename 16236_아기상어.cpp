#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 25;

int map[MAX][MAX];
int checkStep[MAX][MAX];
queue<pair<int, int> > q;
vector<pair<int, int> > fish;
int n;
int sizeOfShark;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y) {
    pair<int, int> p;
    p.first = x;
    p.second = y;
    checkStep[x][y] = 0;
    q.push(p);

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(sizeOfShark < map[nx][ny]) continue;
            else if(checkStep[nx][ny] != -1) continue;
            else {
                p.first = nx;
                p.second = ny;
                checkStep[nx][ny] = checkStep[x][y] + 1;
                q.push(p);
            }
        }

    }
}

int main()
{

    scanf("%d", &n);
    
    memset(map, 0, sizeof(map));
    memset(checkStep, -1, sizeof(checkStep));

    int curSharkX = -1, curSharkY = -1;
    sizeOfShark = 2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);

            // 아기상어위치찾기
            if (map[i][j] == 9)
            {
                curSharkX = i;
                curSharkY = j;
            } else if(map[i][j] != 0) {
                fish.push_back(make_pair(i, j));
            }
        }
    }

    map[curSharkX][curSharkY] = 0;

    sort(fish.begin(), fish.end());

    int ans = 0;
    int cntOfEatenFish = 0;
    while(!fish.empty()) {

        memset(checkStep, -1, sizeof(checkStep));

        // 상어가 이동할 수 있는 위치의 최단거리 구하기
        bfs(curSharkX, curSharkY);

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // cout << "//////////////////////////////////" << endl;

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << checkStep[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // 먹을 수 있는 물고기 탐색
        bool canEat = false;
        vector<pair<int, int> >::iterator feed_it;
        for(auto it = fish.begin(); it != fish.end(); it++) {
            if(map[(*it).first][(*it).second] < sizeOfShark) {
                if(!canEat) {
                    if(checkStep[(*it).first][(*it).second] != -1) {
                        feed_it = it;
                        canEat = true;
                    }
                }
                else {
                    // cout << checkStep[(*feed_it).first][(*feed_it).second] << " / " << checkStep[(*it).first][(*it).second] << endl;
                    if((checkStep[(*it).first][(*it).second] != -1) && (checkStep[(*feed_it).first][(*feed_it).second] > checkStep[(*it).first][(*it).second])) {
                        feed_it = it;
                    } else if((checkStep[(*it).first][(*it).second] != -1) && (checkStep[(*feed_it).first][(*feed_it).second] == checkStep[(*it).first][(*it).second])) {
                        if((*feed_it).first > (*it).first) {
                            feed_it = it;
                        } else if((*feed_it).first == (*it).first) {
                            if((*feed_it).second > (*it).second) {
                                feed_it = it;
                            }
                        }
                    }
                    canEat = true;
                }
            }
        }

        if(!canEat) break;
        // cout << "location: " << (*feed_it).first << " / " << (*feed_it).second << endl;
        // cout << "sharKX: " << curSharkX << " / sharkY: " << curSharkY << endl;
        ans += checkStep[(*feed_it).first][(*feed_it).second];
        curSharkX = (*feed_it).first;
        curSharkY = (*feed_it).second;
        // cout << "ans: " << ans << endl;
        // cout << "shark Size: " << sizeOfShark << endl;
        
        cntOfEatenFish += 1;
        map[(*feed_it).first][(*feed_it).second] = 0;
        if(cntOfEatenFish == sizeOfShark) {
            cntOfEatenFish = 0;
            sizeOfShark += 1;
        }
        fish.erase(feed_it);
    }

    printf("%d\n", ans);

    return 0;
}