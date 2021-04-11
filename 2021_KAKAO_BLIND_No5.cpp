#include <cstring>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 360005;

// string -> int 변환 함수
int convertTimeStringToInt(string time) {
    int result = 0;
    string timePart[3];
    int idx = 0;

    string eachTime = "";
    for(auto t : time) {
        if(t == ':') {
            timePart[idx] = eachTime;
            eachTime = "";
            idx++;
            continue;
        }

        eachTime += t;
    }

    timePart[idx] = eachTime;

    int secBase = 1;
    for(int i = idx; i >= 0; i--) {
        string t = timePart[i];
        int tLength = t.length();
        int tenBase = 1;
        int secTime = 0;
        for(int j = tLength-1; j >= 0; j--) {
            secTime += (t[j] - '0') * tenBase;
            tenBase *= 10;
        }

        result += secTime * secBase;
        secBase *= 60;
    }

    return result;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    long long totalRunTime[MAX];
    memset(totalRunTime, 0, sizeof(totalRunTime));

    int playTime = convertTimeStringToInt(play_time);
    int advTime = convertTimeStringToInt(adv_time);

    vector<pair<int, string> > startLogSecTime;
    for(auto log : logs) {
        string start = "", end = "";
        int switchFlag = 0;
        for(auto ch : log) {
            if(ch == '-') {
                switchFlag = 1;
                continue;
            }

            if(switchFlag) end += ch;
            else start += ch;
        }

        int startTime = convertTimeStringToInt(start), endTime = convertTimeStringToInt(end);
        totalRunTime[startTime]++;
        totalRunTime[endTime]--;
        
        startLogSecTime.push_back(make_pair(startTime, start));
    }

    // 현재 시청중인 시청자 수
    for(int i = 0; i < playTime; i++) totalRunTime[i+1] += totalRunTime[i];
    // 현재 시청중인 시청자들의 누적 재생시간
    for(int i = 0; i < playTime; i++) totalRunTime[i+1] += totalRunTime[i];

    long long maxTotalTime = totalRunTime[advTime-1];
    int intAnsTime = 0;
    for(int i = 0; i + advTime <= playTime; i++) {
        long long tempTotalTime = totalRunTime[i+advTime] - totalRunTime[i];
        if(tempTotalTime > maxTotalTime) {
            maxTotalTime = tempTotalTime;
            intAnsTime = i+1;
        }
    }

    // int -> string 변환을 위한 계산 방식
    int hour = intAnsTime /(60*60);
    int min = (intAnsTime/60)%60;
    int sec = intAnsTime%60;

    string sHour = hour < 10 ? "0" + to_string(hour) : to_string(hour);
    string sMin = min < 10 ? "0" + to_string(min) : to_string(min);
    string sSec = sec < 10 ? "0" + to_string(sec) : to_string(sec);

    answer = sHour + ":" + sMin + ":" + sSec;
    return answer;
}