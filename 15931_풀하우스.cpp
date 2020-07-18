#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    // a : 같은 숫자 카드가 1장 , b : 같은 숫자 카드가 2장 , c : 같은 숫자 카드가 3장 , d : 같은 숫자 카드가 4장 케이스

    int total = 52 - n;

    int minAns = 1e4;
    int maxAns = min(total / 5, 8);

    for(int a = 0; a <= 13; a++) {
        for(int b = 0; b <= 13; b++) {
            for(int c = 0; c <= 13; c++) {
                for(int d = 0; d <= 13; d++) {
                    if(a+2*b+3*c+4*d != total) continue;
                    if(a+b+c+d > 13) continue;
                    int tmp = 0;
                    for(int i = 0; i <= c; i++) {
                        for(int j = 0; j <= d; j++) {
                            int totalB = b + i + 2*j;
                            int totalC = c - i + (d-j);
                            tmp = max(tmp, min(totalB, totalC));
                        }
                    }
                    minAns = min(minAns, tmp);
                }
            }
        }
    }

    printf("%d %d\n", minAns, maxAns);

    return 0;
}