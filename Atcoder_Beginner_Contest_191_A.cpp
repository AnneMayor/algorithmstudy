#include <iostream>

using namespace std;

int main(void) {

    int v, t, s, d;
    scanf("%d %d %d %d", &v, &t, &s, &d);

    int start = v * t;
    int end = v * s;

    if(d >= start && d <= end) printf("No\n");
    else printf("Yes\n");

    return 0;
}