#include <iostream>
#include <queue>

using namespace std;
const int MAX = 10;

queue<int> nums;

int main() {

    for(int i = 0; i < 10; i++) {
        
        int idx;
        scanf("%d", &idx);

        for(int i = 0; i < 8; i++) {
            int num;
            scanf("%d", &num);
            nums.push(num);
        }

        bool flag = false;
        while(true) {

            if(flag) break;

            for(int i = 1; i <= 5; i++) {
                int tmp = nums.front();
                nums.pop();
                if(tmp-i <= 0) {
                    nums.push(0);
                    flag = true;
                    break;
                } else {
                    tmp -= i;
                    nums.push(tmp);
                }
            }

        }

        printf("#%d ", idx);
        while(!nums.empty()) {
            printf("%d ", nums.front());
            nums.pop();
        }
        printf("\n");

    }

    return 0;
}