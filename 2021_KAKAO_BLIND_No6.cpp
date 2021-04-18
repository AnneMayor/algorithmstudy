#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > boardMap[7];
vector<vector< pair<int, int> > > finalOrders;
vector<vector<int> > removingLists;
int isExisted[7];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void decide_final_order(vector<int> & list, int idx, int allBlockCnt, vector<pair<int, int> > & finalList) {
    if(idx >= allBlockCnt) {
        finalOrders.push_back(finalList);
        return ;
    }

    finalList.push_back(boardMap[list[idx]][0]);
    finalList.push_back(boardMap[list[idx]][1]);
    decide_final_order(list, idx+1, allBlockCnt, finalList);
    finalList.pop_back();
    finalList.pop_back();
    finalList.push_back(boardMap[list[idx]][1]);
    finalList.push_back(boardMap[list[idx]][0]);
    decide_final_order(list, idx+1, allBlockCnt, finalList);
    finalList.pop_back();
    finalList.pop_back();

    return ;
}

void decide_removing_order(int cnt, int allBlockCnt, int idx, vector<int> & removingList, vector<int> & isVisited) {

    if(cnt >= allBlockCnt) {
        removingLists.push_back(removingList);
        return ;
    }

    for(int i = 1; i < 7; i++) {
        if(isExisted[i] && !isVisited[i]) {
            isVisited[i] = 1;
            removingList.push_back(i);
            decide_removing_order(cnt+1, allBlockCnt, i, removingList, isVisited);
            isVisited[i] = 0;
            removingList.pop_back();
        }
    }

    return ;
}

bool isRange(int x, int y) {
    return x >= 0 && y >= 0 && x < 4 && y < 4;
}

pair<int, int> findNext(int dir, int curX, int curY, vector<vector<int> > & board) {
    pair<int, int> point;

    if(dir < 4) {
        point.first = curX + dx[dir], point.second = curY + dy[dir];
    } else {
        dir -= 4;
        
        // 여기 부분 정말 주의해서 코딩할 것! 여기서 정말 한나절 잡아먹었다...
        while (isRange(curX + dx[dir], curY + dy[dir]))
        {
            curX += dx[dir];
            curY += dy[dir];
            if(board[curX][curY]) {
                point.first = curX, point.second = curY;
                break;
            }
        }
        point.first = curX, point.second = curY;
    }

    return point;
}

int searchMinPathByBfs(int startX, int startY, int endX, int endY, vector<vector<int> > & board) {

    int isVisited[4][4];
    memset(isVisited, 0, sizeof(isVisited));
    queue<pair<pair<int, int>, int> > q;

    isVisited[startX][startY] = 1;
    q.push({{startX, startY}, 0});
    int result = INT_MAX;

    while (!q.empty())
    {
        int curX = q.front().first.first, curY = q.front().first.second;
        int curStep = q.front().second;
        q.pop();

        if(curX == endX && curY == endY) {
            result = min(result, curStep);
            break;
        }

        for(int i = 0; i < 8; i++) {
            pair<int, int> nextPoint = findNext(i, curX, curY, board);
            int nx = nextPoint.first, ny = nextPoint.second;
            if(isRange(nx, ny) && !isVisited[nx][ny]) {
                isVisited[nx][ny] = 1;
                q.push({{nx, ny}, curStep+1});
            }
        }

    }
    
    return result;
}

int bfs(vector<pair<int, int> > & list, int r, int c, vector<vector<int> > & board) {
    int result = 0;

    vector<vector<int> > tempBoard;
    tempBoard = board;

    for(int i = 0; i < list.size(); i++) {
        if(i == 0) {
            result += searchMinPathByBfs(r, c, list[i].first, list[i].second, tempBoard) + 1;
        } else {
            result += searchMinPathByBfs(list[i-1].first, list[i-1].second, list[i].first, list[i].second, tempBoard) + 1;
        }
        tempBoard[list[i].first][list[i].second] = 0;
    }

    return result;
}

int solution(vector<vector<int>> board, int r, int c) {

    memset(isExisted, 0, sizeof(isExisted));
    int allBlockCnt = 0;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(board[i][j]) {
                allBlockCnt++;
                isExisted[board[i][j]] = 1;
                boardMap[board[i][j]].push_back({i, j});
            }
        }
    }

    // 1. 제거할 카드 순서 구하기
    allBlockCnt /= 2;
    vector<int> removingList;
    vector<int> isVisited(7, 0);
    decide_removing_order(0, allBlockCnt, 0, removingList, isVisited);

    // 2. 각 카드별 제거 순서 구하기
    for(auto list : removingLists) {
        vector<pair<int, int> > finalList;
        decide_final_order(list, 0, allBlockCnt, finalList);
    }

    int answer = INT_MAX;
    for(auto list : finalOrders) {
        answer = min(answer, bfs(list, r, c, board));
    }
    
    return answer;
}