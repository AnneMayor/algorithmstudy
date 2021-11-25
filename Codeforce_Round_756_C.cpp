#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(void) {

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; tc++) {
        int n;
        scanf("%d", &n);
        vector<int> a;
        deque<int> p;
        for(int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            a.push_back(num);
        }

        int lastLeftIdx = (n % 2 == 0 ? n / 2 -1 : n / 2);
        for(int i = lastLeftIdx; i >= 0; i--) p.push_back(a[i]);
        for(int i = n-1; i > lastLeftIdx; i--) p.push_back(a[i]);

        // for(int j : p) cout << j << " ";
        // cout << endl;

        // validation
        deque<int> tempA;
        int start = 0 , end = n-1;
        while (start <= end)
        {
            if(p[start] < p[end]) {
                tempA.push_front(p[start]);
                start++;
            } else {
                tempA.push_back(p[end]);
                end--;
            }
        }

        // for(int data : tempA) cout << data << " ";

        bool isSame = true;
        if(a[0] == tempA[0]) {
            for(int i = 1; i < n; i++) {
                if(a[i] != tempA[i]) {
                    isSame = false;
                    break;
                }
            }
        } else if(a[0] == tempA[n-1]) {
            for(int i = 0; i < n-1; i++) {
                if(a[i+1] != tempA[i]) {
                    isSame = false;
                    break;
                }
            }
        } else isSame = false;

        if(isSame) {
            for(int data : p) {
                printf("%d ", data);
            }
            printf("\n");
        } else printf("-1\n");
    }

    return 0;
}