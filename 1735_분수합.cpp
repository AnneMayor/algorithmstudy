#include <iostream>

using namespace std;

int getGCD(int a, int b) {

    if(b == 0) return a;
    int x = a > b ? a : b;
    int y = a > b ? b : a;
    return getGCD(y, x%y);
}

int main() {

    int an, ad;
    int bn, bd;

    scanf("%d %d", &an, &ad);
    scanf("%d %d", &bn, &bd);

    int gcd = getGCD(ad, bd);

    int ansd = gcd * (ad/gcd) * (bd/gcd);
    int ansn = an * (ansd/ad) + bn * (ansd/bd);

    int ansGcd = getGCD(ansd, ansn);

    printf("%d %d\n", ansn/ansGcd, ansd/ansGcd);

    return 0;
}