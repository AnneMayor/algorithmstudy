#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    vector<int> days;
    int max_day = 0;

    // 다른 사람 풀이 중 가장 최적화(시간, 공간)된 풀이
    // for(int idx = 0; idx < progresses.size(); idx++) {
    //     int day = (100 - progresses[idx]) % speeds[idx] == 0 ? (100-progresses[idx]) / speeds[idx] : (100-progresses[idx]) / speeds[idx] + 1;

    //     if(days.empty() || max_day < day) {
    //         max_day = day;
    //         days.push_back(1);
    //     } else {
    //         days.back()++;
    //     }
    // }

    // for(int idx = 0; idx < progresses.size(); idx++) {
    //     int remain = 100 - progresses[idx];
    //     int workDay = remain % speeds[idx] == 0 ? remain / speeds[idx] : remain / speeds[idx] + 1;
    //     days.push_back(workDay);
    // }
    
    stack<int> order;
    vector<int> answer;
    int startIdx = 0;
    for(auto day : days) {
        if(order.empty()) {
            order.push(day);
            answer.push_back(1);
        } else {
            int releaseDay = order.top();
            order.pop();
            if(releaseDay < day) {
                startIdx++;
                answer.push_back(1);
                order.push(day);
            } else {
                answer[startIdx] += 1;
                order.push(releaseDay);
            }
        }
    }
    
    return answer;
    // return days;
}