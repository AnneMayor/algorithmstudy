#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> water;

int main() {

    int n, l;
    scanf("%d %d", &n, &l);

    int ans = 0;

    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        water.push_back(temp);
    }

    sort(water.begin(), water.end());

    int temp = 0;
    for(int i = 0; i < n; i++) {
        if(temp >= water[i]) {
            continue;
        }

        // cout << "water[i]: " << water[i] << endl;
        // cout << "temp: " << temp << endl;
        
        ans += 1;
        temp = water[i] + l - 0.5;
    }

    printf("%d\n", ans);
    
    return 0;
}