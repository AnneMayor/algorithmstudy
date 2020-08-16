#include <vector>

vector<int> ans;
vector<int> tmp;

void findAns(int sum, int start, int cnt) {

    if(sum < 0 || start > cnt) return ;
    if(sum == 0 && start == cnt) {
        ans.clear();
        for(auto num : tmp) ans.push_back(num);
        return ;
    }
    
    for(int i = 1; i <= 6; i++) {
        tmp.push_back(i);
        findAns(sum-i, start+1, cnt);
        tmp.pop_back();
    }

    return ;
}

vector<int> solution(vector<int> &A, int F, int M) {
    int totalCount = A.size() + F;
    int sumOfArr = 0;
    for(auto num : A) sumOfArr += num;
    int totalSum = totalCount * M - sumOfArr;

    findAns(totalSum, 0, F);

    if(ans.size() <= 0) ans.push_back(0);

    return ans;
    
}
