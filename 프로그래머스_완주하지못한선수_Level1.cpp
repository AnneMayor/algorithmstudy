#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    int numOfCompletion = completion.size();
    for(int idx = 0; idx < numOfCompletion; idx++) {
        if(participant[idx] != completion[idx]) {
            answer = participant[idx];
            break;
        }
    }
    if(answer == "") {
        answer = participant[numOfCompletion];
    }
    return answer;
}