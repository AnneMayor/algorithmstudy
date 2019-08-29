#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e5;

struct Point {

    int x;
    int y;
    int idx;

};

Point points[MAX];
int ansX[MAX];
int ansY[MAX];

bool compare(const Point& p1, const Point& p2) {
    if(p1.x < p2.x) return true;
    else if(p1.x == p2.x) {
        if(p1.y < p2.y) return true;
        return false;
    }
    return false;
}

double absolute(double d) {
    if(d > 0.0) return d;
    else return -d;
}

int main() {

    int n;
    scanf("%d", &n);

    Point p;
    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        p.x = x;
        p.y = y;
        p.idx = i+1;
        points[i] = p;
    }

    sort(points, points+n, compare);

    double mx = -1;
    int a, b;
    int idxAnsX = 0;
    int idxAnsY = 0;

    // 가장 큰 기울기 찾기
    for(int i = 0; i < n-1; i++) {
        // cout << "x: " << points[i].x << " / y: " << points[i].y << endl;
        if(mx < absolute((double)(points[i].y - points[i+1].y) / (double)(points[i].x - points[i+1].x))) {
            mx = absolute((double)(points[i].y - points[i+1].y) / (double)(points[i].x - points[i+1].x));
        }
    }

    // cout << "max: " << mx << endl;

    // 인덱스 찾기
    for(int i = 0; i < n-1; i++) {
        if(mx == absolute((double)(points[i].y - points[i+1].y) / (double)(points[i].x - points[i+1].x))) {
            // cout << "p.x: " << p.x << " / p.y: " << p.y << endl;
            ansX[idxAnsX++] = points[i].idx;
            ansY[idxAnsY++] = points[i+1].idx;
        }
    }

    sort(ansX, ansX+idxAnsX);
    sort(ansY, ansY+idxAnsY);

    a = ansX[0] > ansY[0] ? ansY[0] : ansX[0];
    b = ansX[0] < ansY[0] ? ansY[0] : ansX[0];

    printf("%d %d\n", a, b);

    return 0;
}