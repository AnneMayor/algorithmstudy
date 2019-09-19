#include <deque>
#include <vector>

using namespace std;

deque<int> dq;

vector<int> solution(vector<int> &A, int K) {
    
    int len = A.size();
    vector<int> ans;
    for(int i = 0; i < len; i++) {
        dq.push_back(A[i]);
    }
    
    if(dq.empty()) {
        return ans;
    }
    
    for(int i = 0; i < K; i++) {
        int tmp = dq.back();
        dq.push_front(tmp);
        dq.pop_back();
    }
    
    
    while(!dq.empty()) {
        ans.push_back(dq.front());
        dq.pop_front();
    }
    
    return ans;
    
}