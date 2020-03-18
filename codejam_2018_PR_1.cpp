#include <iostream>
#include <string>

using namespace std;

int main() {

    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int a, b, n, done = 0;
        cin >> a >> b >> n;

        while (true)
        {
            int middle = (a+1+b) / 2;
            cout << middle << endl;
            string result;
            cin >> result;
            if(result == "CORRECT" || done > n) break;
            else if(result == "TOO_SMALL") a = middle+1;
            else b = middle - 1;
            done++;
        }

    }

    return 0;
}