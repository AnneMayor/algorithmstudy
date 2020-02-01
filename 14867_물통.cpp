#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

const int MAX = 1e5+5;

struct Water {
    int a;
    int b;
    int step;
};

queue<Water> q;
// 0: A is full , 1: A is empty , 2: B is full , 3: B is empty
bool isVisited[MAX][4];

int bfsSearch(int a, int b, int fa, int fb) {
    isVisited[0][1] = true;
    isVisited[0][3] = true;
    Water w;
    w.a = 0;
    w.b = 0;
    w.step = 0;
    q.push(w);

    while (!q.empty())
    {
        w = q.front();
        q.pop();
        int na, nb, count;
        na = w.a;
        nb = w.b;
        count = w.step;

        if(na == fa && nb == fb) return count;

        // fill
        if(!isVisited[nb][0]) {
            isVisited[nb][0] = true;
            w.a = a;
            w.b = nb;
            w.step = count+1;
            q.push(w);
        }
        if(!isVisited[na][2]) {
            isVisited[na][2] = true;
            w.a = na;
            w.b = b;
            w.step = count+1;
            q.push(w);
        }

        // empty
        if(!isVisited[nb][1]) {
            isVisited[nb][1] = true;
            w.a = 0;
            w.b = nb;
            w.step = count+1;
            q.push(w);
        }
        if(!isVisited[na][3]) {
            isVisited[na][3] = true;
            w.a = na;
            w.b = 0;
            w.step = count+1;
            q.push(w);
        }

        // move
        int ma, mb;
        if(na <= b-nb) {
            mb = na+nb > b ? b : na+nb;
            ma = 0;
        } else {
            ma = na - (b-nb);
            mb = b;
        }

        if(ma) {
            if(!isVisited[ma][2]) {
                isVisited[ma][2] = true;
                w.a = ma;
                w.b = mb;
                w.step = count+1;
                q.push(w);
            }
        } else {
            if (!isVisited[mb][1])
            {
                isVisited[mb][1] = true;
                w.a = ma;
                w.b = mb;
                w.step = count + 1;
                q.push(w);
            }
        }

        if(nb <= a - na) {
            ma = na + nb > a ? a : na+nb;
            mb = 0;
        } else {
            ma = a;
            mb = nb - (a-na);
        }

        if(mb) {
            if(!isVisited[mb][0]) {
                isVisited[mb][0] = true;
                w.a = ma;
                w.b = mb;
                w.step = count+1;
                q.push(w);
            }
        } else {
            if(!isVisited[ma][3]) {
                isVisited[ma][3] = true;
                w.a = ma;
                w.b = mb;
                w.step = count+1;
                q.push(w);
            }
        }

    }
    
    return -1;
}

int main() {

    int a, b, fa, fb;
    scanf("%d %d %d %d", &a, &b, &fa, &fb);
    memset(isVisited, false, sizeof(isVisited));

    int ans = bfsSearch(a, b, fa, fb);

    printf("%d\n", ans);

    return 0;
}