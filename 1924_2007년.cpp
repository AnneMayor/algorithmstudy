#include <iostream>

using namespace std;
int dayOfM[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char dayOfWeek[][7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main() {

    int x, y;
    scanf("%d %d", &x, &y);

    // 0: SUN ~ 6: SAT
    int sum = 0;

    // 달 체크
    for(int i = 1; i < x; i++) {
        sum += dayOfM[i];
    }

    // 일 체크
    sum += y;

    printf("%s\n", dayOfWeek[sum%7]);

    return 0;
}