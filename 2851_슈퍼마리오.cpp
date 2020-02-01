#include <iostream>
#include <math.h>

using namespace std;

int main() {

    int arrMush[15];

    for(int i = 0; i < 10; i++) {
        scanf("%d", &arrMush[i]);
    }

    int curScore = 0;
    int diff = 100;
    for(int i = 0; i < 10; i++) {
        curScore += arrMush[i];
        if(diff >= abs(100-curScore)) diff = abs(100-curScore);
        else {
            curScore -= arrMush[i];
            break;
        }        
    }

    printf("%d\n", curScore);

    return 0;
}