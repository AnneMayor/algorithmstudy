#include <vector>

using namespace std;

int solution(vector<int> &A) {
    
    int ret = 0;
    int len = A.size();
    
    for(int i = 0; i < len; i++) {
        ret ^= A[i];
    }
    
    return ret;
    
}