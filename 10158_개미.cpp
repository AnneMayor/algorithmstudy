#include <iostream>

using namespace std;

int main() {

    int w, h;
    scanf("%d %d", &w, &h);
    int x, y;
    scanf("%d %d", &x, &y);
    int t;
    scanf("%d", &t);

    int a = (x+t)/w;
    int b = (y+t)/h;

    if(a%2 == 0) {
        x = (x+t)%w;
    } else {
        x = w-(x+t)%w;
    }

    if(b%2 == 0) {
        y = (y+t)%h;
    } else {
        y = h - (y+t)%h;
    }

    printf("%d %d\n", x, y);

    return 0;
}