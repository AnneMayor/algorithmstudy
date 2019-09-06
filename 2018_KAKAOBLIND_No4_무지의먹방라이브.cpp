#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long long, int>> nums;
vector<int> ans;

bool comp(const pair<long long, int> & n1, const pair<long long, int> & n2) {
    return n1.second < n2.second;
}

int solution(vector<int> food_times, long long k)
{

    int answer = 0;
    long long len = food_times.size();

    pair<long long, int> p;
    for (int i = 0; i < len; i++)
    {
        p.first = (long long) food_times[i];
        p.second = i + 1;
        nums.push_back(p);
    }

    sort(nums.begin(), nums.end());

    long long idx = 0;
    long long tmp = 0;

    for( ; idx < len; idx++) {
        tmp = idx == 0? nums[idx].first : (nums[idx].first-nums[idx-1].first);

        if(k - tmp*(len-idx) < 0) break;

        k -= tmp * (len-idx);
    }

    sort(nums.begin()+idx, nums.end(), comp);

    if(idx >= nums.size()) answer = -1;
    else answer = nums[idx+k%(len-idx)].second;

    return answer;
}