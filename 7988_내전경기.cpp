#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 205;

map<string, int> member;
vector<vector<int> > m(MAX);
queue<pair<int, int> > q;
bool flag;

int check[MAX];

void bfs(int person, int team) {

    check[person] = team;
    q.push(make_pair(person, team));

    while (!q.empty()) 
    {
        person = q.front().first;
        team = q.front().second;
        q.pop();

        for(int i = 0; i < m[person].size(); i++) {
            if(check[m[person][i]] != 0) {
                if(check[m[person][i]] == team) {
                    flag = false;
                    return ;
                }
            } else {
                if(team == 1) {
                    check[m[person][i]] = 2;
                    q.push(make_pair(m[person][i], 2));
                } else {
                    check[m[person][i]] = 1;
                    q.push(make_pair(m[person][i], 1));
                }
            }
        }
    }
    
}


int main() {

    cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;

        memset(check, 0, sizeof(check));
        member.clear();
        for(int i = 0; i < MAX; i++) {
            m[i].clear();
        }
        m.clear();
        while (!q.empty())
        {
            q.pop();
        }
        flag = true;

        int idx = 0;
        for(int i = 0; i < n; i++) {
            string p1, p2;
            cin >> p1 >> p2;
            
            if(member.empty()) {
                m[0].push_back(1);
                m[1].push_back(0);
                member.insert(make_pair(p1, idx++));
                member.insert(make_pair(p2, idx++));
            } else {
                int tmpIdx1 = -1, tmpIdx2 = -1;
                if(member.find(p1) != member.end()) {
                    tmpIdx1 = member.at(p1);
                } else {
                    tmpIdx1 = idx++;
                }

                if(member.find(p2) != member.end()) {
                    tmpIdx2 = member.at(p2);
                } else {
                    tmpIdx2 = idx++;
                }
                member.insert(make_pair(p1, tmpIdx1));
                member.insert(make_pair(p2, tmpIdx2));
                m[tmpIdx1].push_back(tmpIdx2);
                m[tmpIdx2].push_back(tmpIdx1);
            }

        }

        // for(int j = 0; j < idx; j++) {
        //     for(int k = 0; k < m[j].size(); k++) {
        //         cout << m[j][k] << " ";
        //     }
        //     cout << endl;
        // }

        for(int i = 0; i < idx; i++) {
            if(check[i] == 0) {
                bfs(i, 1);
            }
        }

        // for(int j = 0; j < idx; j++) {
        //     cout << check[j] << " ";
        // }
        // cout << endl;
        
        printf("#%d ", tc);
        if(flag) {
            printf("Yes");
        } else {
            printf("No");
        }
        printf("\n");

    }
    

    

    return 0;
}