#include <iostream>

using namespace std;

const int MAX = 100005;

int n, m;
int note[MAX];

// 이분탐색 중 parametric search에 해당!
// 탐색하려고 하는 값을 레슨 길이의 합으로 두기(Start: 1 ~ End: 1부터 N까지의 합)
// 여기서 포인트!: 블루레이는 M개보다 작거나 같을 경우에 레슨 길이의 합 성립.

bool isPossible(int mid) {

    int cntOfBlueray = 1;
    int sum = 0;

    for(int i = 0; i < n; i++) {
        
        if(note[i] > mid) {
            return false;
        }

        sum += note[i];

        if(sum > mid) {
            sum = note[i];
            cntOfBlueray += 1;
        }

    }

    return m >= cntOfBlueray;

}

int main() {

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n ;i++) {
        scanf("%d", &note[i]);
    }

    int start = note[0];
    int end = 0;
    for(int i = 0; i < n; i++) {
        end += note[i];
    }

    int ans = 0;

    while(start <= end) {

        int mid = (start + end) / 2;

        if(isPossible(mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }

    }

    printf("%d\n", ans);
    
    return 0;
}