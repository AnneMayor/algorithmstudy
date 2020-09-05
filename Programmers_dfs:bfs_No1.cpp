#include <string>
#include <vector>

using namespace std;

int answer = 0;

void findAns(int cur, int cnt, int n, vector<int> & numList, int target) {

    if(cnt > n) return ;
    if(cnt == n) {
        if(cur == target) answer++;
        return ;
    }

    findAns(cur+numList[cnt], cnt+1, n, numList, target);
    findAns(cur-numList[cnt], cnt+1, n, numList, target);

    return ;
}

int solution(vector<int> numbers, int target) {
    int total = 0;
    for(auto num : numbers) {
        total += num;
    }
    if(total < target) return 0;
    if(total == target) return 1;

    int n = numbers.size();
    findAns(0, 0, n, numbers, target);

    return answer;
}