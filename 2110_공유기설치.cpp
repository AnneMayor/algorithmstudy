#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 2e5 + 5;

int nums[MAX];

int main()
{

    int n, c;
    scanf("%d %d", &n, &c);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    sort(nums, nums + n);

    int start = nums[1] - nums[0];
    int end = nums[n - 1] - nums[0];
    int ans = 0;
    while (start <= end)
    {

        int mid = (start + end) / 2;

        // 공유기 설치 가능 대수 찾기 && 0번째 자리는 항상 설치
        int s = 0;
        int e = 1;
        int cntOfWifi = 1;
        while (s < e && e < n)
        {
            if (nums[s] + mid <= nums[e])
            {
                cntOfWifi++;
                s = e;
                e++;
            }
            else
            {
                e++;
            }
        }

        // cout << "cntOfWifi: " << cntOfWifi << endl;
        // cout << "mid: " << mid << endl;
        if (cntOfWifi < c)
        {
            end = mid - 1;
        }
        else if (cntOfWifi >= c)
        {
            ans = mid;
            start = mid + 1;
        }


        // cout << "start: " << start << " / end: " << end << endl;
        
    }

    printf("%d\n", ans);

    return 0;
}