#include <bits/stdc++.h>

using namespace std;

char switchLowerCase(char ch) {
    return ch >= 'a' && ch <= 'z'? ch : ch - 'A' + 'a';
}

int solution(string word, vector<string> pages) {

    int answer = 0;
    regex re(R"(<meta property="og:url" .*/>)");
    smatch matchLink;
    map<string, vector<string> > pagesGroup; // value first: 기본점수 / second: 링크점수
    map<string, int> idxGroup;
    vector<string> links;
    int score[50];

    memset(score, 0, sizeof(score));

    // word 소문자 치환
    for(int i = 0; i < (int) word.length(); i++) {
        word[i] = switchLowerCase(word[i]);
    }

    for(int i = 0; i < pages.size(); i++) {

        // link
        string link = "";
        links.clear();
        if(regex_search(pages[i], matchLink, re)) {
            int startLinkIdx = matchLink.str().find("\"https://");
            link = matchLink.str().substr(startLinkIdx);
            int len = link.length();
            link = link.substr(0, len-2);
            cout << "link: " << link << endl;
        }
        idxGroup.insert(make_pair(link, i));

        // body
        int startIdx = pages[i].find("<body>") + 6;
        int lastIdx = pages[i].find("</body>");

        // 기본점수 구하기
        string tmp = "";
        bool nowInBracket = false;
        for(int j = startIdx; j < lastIdx; j++) {
            char ch = switchLowerCase(pages[i][j]);
            if(nowInBracket) {

            } else if(ch == ' ' || !(ch >= 'a' && ch <= 'z')) {
                if(tmp != "" && tmp == word) score[i]++;
                tmp = "";
                if(ch == '<') nowInBracket = true;
            } else tmp += ch;
        }
        if(tmp != "" && tmp == word) score[i]++;

        string tmpPage = pages[i].substr(startIdx);
        int idx = tmpPage.find("<a href");
        while (idx != string::npos)
        {
            string externalLink = "";
            tmpPage = tmpPage.substr(idx+7);
            tmpPage = tmpPage.substr(tmpPage.find("https://"));
            externalLink = tmpPage.substr(0, tmpPage.find("\""));
            externalLink = '"' + externalLink + '"';
            links.push_back(externalLink);
            idx = tmpPage.find("<a href");
        }

        pagesGroup.insert(make_pair(link, links));
    }

    vector<double> matchingPoints(pages.size(), 0);
    for(auto p : idxGroup) {
        matchingPoints[p.second] += score[p.second];
        double linkPoint = (double) score[p.second] / (double) pagesGroup[p.first].size();
        for(int j = 0; j < (int) pagesGroup[p.first].size(); j++) {
            if(idxGroup.find(pagesGroup[p.first][j]) != idxGroup.end()) {
                int linkIdx = idxGroup[pagesGroup[p.first][j]];
                matchingPoints[linkIdx] += linkPoint;
            }
        }
    }
    

    for(int i = 0; i < (int) matchingPoints.size(); i++) {
        if(matchingPoints[answer] < matchingPoints[i]) {
            answer = i;
        }
    }

    return answer;
}