
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int n = 1 << numbers.size();
    int answer = 0;

    for(int i = 1; i < n; i++) {
        int temp = 0;
        for(int j = 0; j < numbers.size(); j++) {
            if(i&(1<<j)) temp -= numbers[j];
            else temp += numbers[j];
        }
        if(temp == target) answer++;
    }

    return answer;
}