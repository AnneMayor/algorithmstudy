#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 105;

struct Point {
    int num;
    int cntOfNum;
};
int A[MAX][MAX];
int result[MAX][MAX];
int colNum, rowNum;
int cntOfNumber[MAX];

bool comp(const Point & p1, const Point & p2) {
    if(p1.cntOfNum == p2.cntOfNum) {
        return p1.num < p2.num;
    }
    return p1.cntOfNum < p2.cntOfNum;
}

void rMove() {

    int tmpCol = 0;

    for(int i = 0; i < rowNum; i++) {
        for(int j = 0; j < colNum; j++) {
            result[i][j] = A[i][j];
        }
    }

    memset(A, 0, sizeof(A));

    for(int i = 0; i < rowNum; i++) {
        vector<Point> v;
        memset(cntOfNumber, 0, sizeof(cntOfNumber));

        for(int j = 0; j < colNum; j++) {
            cntOfNumber[result[i][j]]++;
        }

        for(int j = 1; j <= 100; j++) {
            if(cntOfNumber[j] > 0) {
                Point p;
                p.num = j;
                p.cntOfNum = cntOfNumber[j];
                v.push_back(p);
            }
        }

        sort(v.begin(), v.end(), comp);

        if(tmpCol < v.size()*2) tmpCol = v.size()*2;

        int idx = 0;
        for(int j = 0; j < v.size(); j++) {
            A[i][idx++] = v[j].num;
            A[i][idx++] = v[j].cntOfNum;
        }
    }

    colNum = tmpCol;

    return ;
}

void cMove() {

    int tmpRow = 0;
    for(int i = 0; i < rowNum; i++) {
        for(int j = 0; j < colNum; j++) {
            result[i][j] = A[i][j];
        }
    }

    memset(A, 0, sizeof(A));

    for(int i = 0; i < colNum; i++) {
        vector<Point> v;
        memset(cntOfNumber, 0, sizeof(cntOfNumber));

        for(int j = 0; j < rowNum; j++) {
            cntOfNumber[result[j][i]]++;
        }

        for(int j = 1; j <= 100; j++) {
            if(cntOfNumber[j] > 0) {
                Point p;
                p.num = j;
                p.cntOfNum = cntOfNumber[j];
                v.push_back(p);
            }
        }

        sort(v.begin(), v.end(), comp);

        if(tmpRow < v.size()*2) tmpRow = v.size()*2;
        
        int idx = 0;
        for(int j = 0; j < v.size(); j++) {
            A[idx++][i] = v[j].num;
            A[idx++][i] = v[j].cntOfNum;
        }
    }

    rowNum = tmpRow;
    return ;
}

void rcCalculate() {
    if(rowNum >= colNum) {
        rMove();
    } else {
        cMove();
    }

    memset(result, 0, sizeof(result));

    return ;
}

int main() {

    int r, c, k;
    scanf("%d %d %d", &r, &c, &k);
    memset(A, 0, sizeof(A));
    memset(result, 0, sizeof(result));

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    colNum = 3, rowNum = 3;
    int time = 0;
    while (1)
    {
        if(time > 100 || A[r-1][c-1] == k) {
            if(time > 100) time = -1;
            break;
        }   
        rcCalculate();
        time++;
    }
    
    printf("%d\n", time);

    return 0;
}