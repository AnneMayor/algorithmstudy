#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    string outputFilePath = "output.txt";
    ofstream out(outputFilePath);

    for(int tc = 1; tc <= T; tc++) {
        long long n, k;
        scanf("%lld %lld", &n, &k);

        while (k != 1)
        {
            if(n%2 == 0 && k%2 == 1) {
                n--;
                k--;
            } else {
                n /= 2;
                k /= 2;
            }
        }
        
        printf("Case #%d: %lld %lld\n", tc, n/2, (n-1)/2);
        if(out.is_open()) {
            out << "Case #" << tc << ": " << n/2 << " " << (n-1)/2 << "\n";
        }
    }

    out.close();

    return 0;
}