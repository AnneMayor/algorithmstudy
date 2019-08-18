#include <iostream>

using namespace std;

int findMax(int nums[], int idx, int len) {
    
    int max = -1;
    int maxIdx = 0;
    
    for(int i = idx+1; i < len; i++) {
        if(max < nums[i]) {
            max = nums[i];
            maxIdx = i;
        }
    }
    
    return maxIdx;
    
}

int n;
int nums[1000002];

int main() {
    
    int T;
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        
        scanf("%d", &n);
        
        long long int ans = 0;
        
        for(int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
        }
        
        long long int max = -1;
        long long int minus = 0;
        int maxIdx = -1;
        
        // max값 위치 찾기
        for(int i = 0; i < n; i++) {
            if(max <= nums[i]) {
                max = nums[i];
                maxIdx = i;
            }
        }
        
        if(maxIdx >= n-1) {
            for(int i = 0; i < n; i++) {
                if(i == maxIdx) continue;
                minus += nums[i];
            }
            
            ans = max*maxIdx - minus;
        } else if(maxIdx > 0){
            
            int temp = maxIdx;
            for(int i = 0; i < maxIdx; i++) {
                minus += nums[i];
            }
            ans += maxIdx*max-minus;
            int count = 0;
            
            while(temp < n-1) {
                temp = findMax(nums, maxIdx, n);
                count = temp-maxIdx;
                minus = 0;
                for(int i = maxIdx+1; i <= maxIdx+count; i++) {
                    minus += nums[i];
                }
                max = nums[temp];
                ans += max*count - minus;
                maxIdx = temp;
            }
        }
        
        printf("#%d %lld\n", t, ans);
        
    }
    
    return 0;
}
