#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

bool comp(pair<int, int> & p1, pair<int, int> & p2) {
    if(p1.first == p2.first) {
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    int n = (int) genres.size();
    vector<int> answer;
    map<string, int> gen;
    for(int i = 0; i < n; i++) {
        if(gen.find(genres[i]) == gen.end()) {
            gen[genres[i]] = plays[i];
        } else {
            int score = gen[genres[i]];
            gen[genres[i]] = score + plays[i];
        }
    }

    vector<pair<int, string> > sorted_gen;
    for(auto g : gen) {
        sorted_gen.push_back(make_pair(g.second, g.first));
    }

    sort(sorted_gen.begin(), sorted_gen.end(), greater<pair<int, string> >());
    for(auto g : sorted_gen) {
        vector<pair<int, int> > playList;
        for(int i = 0; i < n; i++) {
            if(g.second.compare(genres[i]) == 0) {
                playList.push_back(make_pair(plays[i], i));
            }
        }
        sort(playList.begin(), playList.end(), comp);
        if(playList.size() < 2) answer.push_back(playList[0].second);
        else {
            answer.push_back(playList[0].second);
            answer.push_back(playList[1].second);
        }
    }
    return answer;
}