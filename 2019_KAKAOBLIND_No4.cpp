#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
// map구조: 하나의 pair<string, pair<단어 길이, 접두사: 1, 접미사: 2> > , 여러 개의 pair<key 위치, word 인덱스>
map<pair<string, pair<int, int> > , vector<int>> ht;

vector<int> solution(vector<string> words, vector<string> queries) {

    vector<int> answer;

    int wLen = words.size();
    // word 넣기
    for(int i = 0; i < wLen; i++) {
        int len = words[i].length();
        string tmp = "";
        for(int j = 0; j < len; j++) {
            tmp += words[i][j];
            ht[make_pair(tmp,make_pair(len, 2))].push_back(i+1);
        }

        tmp = "";
        for(int j = len-1; j >= 0; j--) {
            tmp = words[i].substr(j);
            ht[make_pair(tmp, make_pair(len, 1))].push_back(i+1);
        }

        ht[make_pair("?", make_pair(len, 3))].push_back(i+1);
    }

    int qLen = queries.size();

    // query 탐색
    for(int i = 0 ; i < qLen; i++) {
        int len = queries[i].length();
        string tmp = "";
        int flag = -1;
        if(queries[i][0] == '?') flag = 1;
        else if(queries[i][len-1] == '?') flag = 2;

        for(int j = 0; j < len; j++) {
            if(queries[i][j] != '?') tmp += queries[i][j];
        }

        pair<string, pair<int, int> > key;
        if(tmp == "") {
            key.first = "?";
            key.second.first = len;
            key.second.second = 3;

            if(ht.find(key) != ht.end()) {
                answer.push_back(ht[key].size());
            } else {
                answer.push_back(0);
            }

        }else {
            
            key.first = tmp;
            key.second.first = len;
            key.second.second = flag;

            if(ht.find(key) != ht.end()) {
                answer.push_back(ht[key].size());
            } else {
                answer.push_back(0);
            }
        }

    }

    return answer;
}