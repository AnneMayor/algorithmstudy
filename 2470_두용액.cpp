#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<long long> numList;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        long long num;
        scanf("%lld", &num);
        numList.push_back(num);
    }

    sort(numList.begin(), numList.end());

    int beforePlusIdx = -1;
    for(int i = 0; i < n; i++) {
        if(numList[i] >= 0) {
            beforePlusIdx = i;
            break;
        }
    }

    int prev = 0, next = beforePlusIdx;
    int num1 , num2;
    if(next < 0) {
        num1 = numList[n-2], num2 = numList[n-1];
    } else if(next == 0){
        num1 = numList[0], num2 = numList[1];
    } else {
        next = n-1;
        long long min = 1e12;
        while (prev < next)
        {
            long long sum = numList[prev] + numList[next];
            if(abs(sum) < min) {
                min = abs(sum);
                num1 = numList[prev], num2 = numList[next];
            }

            if(sum < 0) prev++;
            else next--;
        }
    }

    printf("%d %d\n", num1, num2);

    return 0;
}