#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 1e4+5;

vector<vector<int> > answer;
int jordiMap[MAX][MAX];
bool comp(vector<int> & p1, vector<int> & p2) {
    if(p1[0] == p2[0]) {
        if(p1[1] == p2[1]) return p1[2] < p2[2];
        return p1[1] < p2[1];
    }
    return p1[0] < p2[0];
}

bool isOkay(int n) {
    for(int i = n; i > 0; i--) {
        for(int j = 0; j <= n; j++) {
            if(jordiMap[i][j] & 1) {
                // 기둥 아랫부분
                if(i != n && !(jordiMap[i][j] & 4) && !(jordiMap[i][j] & 8) && !(jordiMap[i][j] & 2)) {
                    return false;
                }
            }
        }
    }

    for(int i = n ; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            if(jordiMap[i][j] & 8) {
                // 보 왼쪽부분
                if(!(jordiMap[i][j] & 2) && (!(jordiMap[i][j] & 4) || !(jordiMap[i][j+1] & 8)) && !(jordiMap[i][j+1] & 2)) {
                    return false;
                }
            }
        }
    }

    return true;
}

void removeBuilding(int n, int y, int x, int building) {
    int nx = n-x;
    if(building == 0) {
        // 기둥
        jordiMap[nx][y] ^= 1;
        jordiMap[nx-1][y] ^= 2;
        if(!isOkay(n)) {
            jordiMap[nx][y] |= 1;
            jordiMap[nx-1][y] |= 2;
        }
    } else {
        // 보
        jordiMap[nx][y] ^= 8;
        jordiMap[nx][y+1] ^= 4;
        if(!isOkay(n)) {
            jordiMap[nx][y] |= 8;
            jordiMap[nx][y+1] |= 4;
        }
    }
}

void constructBuilding(int n, int y, int x, int building) {
    int nx = n-x;
    if(building == 0) {
        // 기둥
        if(nx == n || (jordiMap[nx][y] & 4) || (jordiMap[nx][y] & 8) || (jordiMap[nx][y] & 2)) {
            jordiMap[nx][y] |= 1;
            jordiMap[nx-1][y] |= 2;
        }
    } else {
        // 보
        if((jordiMap[nx][y] & 2) || ((jordiMap[nx][y] & 4) && (jordiMap[nx][y+1] & 8)) || (jordiMap[nx][y+1] & 2)) {
            jordiMap[nx][y] |= 8;
            jordiMap[nx][y+1] |= 4;
        }
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    memset(jordiMap, 0, sizeof(jordiMap));
    for(auto point : build_frame) {
        if(point[3] == 0) {
            removeBuilding(n, point[0], point[1], point[2]);
        } else {
            constructBuilding(n, point[0], point[1], point[2]);
        }
    }

    // Map 검사
    for(int i = n; i > 0; i--) {
        for(int j = 0; j <= n; j++) {
            if(jordiMap[i][j] & 1) {
                // 기둥 아래부분
                vector<int> temp;
                temp.push_back(j);
                temp.push_back(n-i);
                temp.push_back(0);
                answer.push_back(temp);
            }
        }
    }

    for(int i = n ; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            if(jordiMap[i][j] & 8) {
                // 보 왼쪽
                vector<int> temp;
                temp.push_back(j);
                temp.push_back(n-i);
                temp.push_back(1);
                answer.push_back(temp);
            }
        }
    }

    sort(answer.begin(), answer.end(), comp);

    return answer;
}