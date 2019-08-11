#include <iostream>

using namespace std;

int main() {

    double orange, apple, pineapple;
    double numOfOrange, numOfApple, numOfPineapple;

    scanf("%lf %lf %lf", &orange, &apple, &pineapple);
    scanf("%lf %lf %lf", &numOfOrange, &numOfApple, &numOfPineapple);

    double o1, a1, p1;
    o1 = orange / numOfOrange;
    a1 = apple / numOfApple;
    p1 = pineapple / numOfPineapple;

    double cnt = min(o1, min(a1, p1));

    double o2, a2, p2;
    o2 = cnt * numOfOrange;
    a2 = cnt * numOfApple;
    p2 = cnt * numOfPineapple;

    // cout << o2 << " " << a2 << " " << p2 << endl;

    printf("%.6f %.6f %.6f\n", orange-o2, apple-a2, pineapple-p2);
    return 0;
}