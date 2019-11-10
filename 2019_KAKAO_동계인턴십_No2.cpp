#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool comp(const string &s1, const string &s2)
{
    return s1.length() < s2.length();
}

set<string> chList;

vector<string> split(string str, char delimiter)
{
    vector<string> internal;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimiter))
    {
        internal.push_back(temp);
    }

    return internal;
}

vector<int> solution(string s)
{

    vector<int> answer;
    int sLen = s.length();
    s = s.substr(1, sLen - 2);

    vector<string> sList = split(s, '}');

    sort(sList.begin(), sList.end(), comp);

    int len = sList.size();

    for (int i = 0; i < sList.size(); i++)
    {
        vector<string> tmp = split(sList[i], ',');
        for (int j = 0; j < tmp.size(); j++)
        {
            if(tmp[j].empty()) continue;
            if(tmp[j][0] == '{') tmp[j] = tmp[j].substr(1);
            if (chList.find(tmp[j]) == chList.end())
            {
                chList.insert(tmp[j]);
                answer.push_back(stoi(tmp[j]));
            }
        }
    }

    return answer;
}