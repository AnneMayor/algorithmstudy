#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define ll long long
#define x first
#define y second

int findIndex(set<int> & group, int pos, int dir) {
    if(dir > 0) {
        // 오른쪽 검사
        auto idx = group.upper_bound(pos);
        if(idx == group.end()) return int(1e9);
        return *idx;
    } else {
        // 왼쪽 검사
        auto idx = group.lower_bound(pos);
        if(idx == group.begin()) return -int(1e9);
        return *(--idx);
    }
}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int r, c;
        scanf("%d %d", &r, &c);

        ll total = 0;
        ll ans = 0;
        queue<pii> possibleSpaces;
        vector<set<int> > rows(r+5), cols(c+5);
        int danceRoom[r+5][c+5];
        int eachPositionRound[r+5][c+5];
        memset(eachPositionRound, 0, sizeof(eachPositionRound));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                scanf("%d", &danceRoom[i][j]);
                total += danceRoom[i][j];
                possibleSpaces.push(make_pair(i, j));
                rows[i].insert(j);
                cols[j].insert(i);
            }
        }

        for(int i = 0, round = 0; ; i++) {
            // 1단계: 가능한 dancer 점수 합산
            vector<pii> failedSpaces;
            round++;
            while (!possibleSpaces.empty())
            {
                pii position = possibleSpaces.front();
                possibleSpaces.pop();
                
                if(eachPositionRound[position.x][position.y] == round) continue;
                eachPositionRound[position.x][position.y]  = round;

                int cntOfAround = 0, totalScore = 0, z;
                // 4방향 검사
                z = findIndex(rows[position.x], position.y, 1);
                if(z < c) {cntOfAround++; totalScore += danceRoom[position.x][z];}
                z = findIndex(rows[position.x], position.y, -1);
                if(z >= 0) {cntOfAround++; totalScore += danceRoom[position.x][z];}
                z = findIndex(cols[position.y], position.x, 1);
                if(z < r) {cntOfAround++; totalScore += danceRoom[z][position.y];};
                z = findIndex(cols[position.y], position.x, -1);
                if(z >= 0) {cntOfAround++; totalScore += danceRoom[z][position.y];};

                if(danceRoom[position.x][position.y] * cntOfAround < totalScore) failedSpaces.push_back(make_pair(position.x, position.y));
            }

            ans += total;
            if(failedSpaces.empty()) break;

            // 2단계: 탈락할 dancer 점수 삭제
            round++;
            
            for (pii & p : failedSpaces)
            {   
                if(eachPositionRound[p.x][p.y] == round) continue;
                eachPositionRound[p.x][p.y]  = round;

                total -= danceRoom[p.x][p.y];
                rows[p.x].erase(p.y);
                cols[p.y].erase(p.x);
            }

            // 3단계: 탈락한 dancer 동서남북 방향으로 다음 탈락 가능한 dancer 큐에 넣기
            round++;

            for (pii & p : failedSpaces)
            {
                if(eachPositionRound[p.x][p.y] == round) continue;
                eachPositionRound[p.x][p.y]  = round;

                int z;
                // 4방향 검사
                z = findIndex(rows[p.x], p.y, 1);
                if(z < c) {possibleSpaces.push(make_pair(p.x, z));};
                z = findIndex(rows[p.x], p.y, -1);
                if(z >= 0) {possibleSpaces.push(make_pair(p.x, z));};
                z = findIndex(cols[p.y], p.x, 1);
                if(z < r) {possibleSpaces.push(make_pair(z, p.y));};
                z = findIndex(cols[p.y], p.x, -1);
                if(z >= 0) {possibleSpaces.push(make_pair(z, p.y));};
            }
            
        }

        printf("Case #%d: %lld\n", tc, ans);

    }

    return 0;
}