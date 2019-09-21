#include <iostream>
#include <set>
#include <string>
#include <queue>

using namespace std;

int map[3][3];
set<string> isDupulicate;
queue<string> q;
int dir[] = {-1, 1, 3, -3};

int bfs(string st) {
    int depth = 0;
    q.push(st);
    isDupulicate.insert(st);

    while (!q.empty())
    {
        int len = q.size();
        for(int i = 0; i < len; i++) {
            st = q.front();
            q.pop();

            if(st == "123456780") {
                return depth;
            }

            int zero;
            for(int j = 0; j < 9; j++) {
                if(st[j] == '0') {
                    zero = j;
                    break;
                }
            }

            for(int j = 0; j < 4; j++) {
                if(j < 2) {
                    if((zero+dir[j]) / 3 != (zero / 3)) continue;
                }

                if(zero+dir[j] < 0 || zero + dir[j] >= 9) continue;

                string str = st;
                swap(str[zero+dir[j]], str[zero]);
                if(isDupulicate.find(str) == isDupulicate.end()) {
                    isDupulicate.insert(str);
                    q.push(str);
                }
            }
        }

        depth++;
    }

    return -1;

}

int main() {

    string start = "";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &map[i][j]);
            start += map[i][j] + '0';
        }
    }

    printf("%d\n", bfs(start));
    return 0;
}