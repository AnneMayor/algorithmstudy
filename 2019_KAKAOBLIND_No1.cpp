#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> stList;

int solution(string s)
{
    int answer = 0;

    int len = s.length();

    if(len == 1) {
        answer = 1;
        return answer;
    }

    for (int i = 1; i <= len / 2; i++)
    {
        string result = "";
        int cntOfChar = 0;
        stList.clear();
        int idx = -1;
        for (int j = 0; j <= len - i; j += i)
        {
            string tmp = s.substr(j, i);
            if (stList.size() == 0)
            {
                stList.push_back(tmp);
                cntOfChar++;
            }
            else
            {
                if (stList.back() == tmp)
                {
                    cntOfChar++;
                }
                else
                {
                    if (cntOfChar > 1)
                    {
                        result += to_string(cntOfChar) + stList.back();
                    }
                    else
                        result += stList.back();

                    cntOfChar = 1;
                    stList.push_back(tmp);
                }
            }

            idx = j;
        }

        idx += i;

        if (cntOfChar > 1)
        {
            result += to_string(cntOfChar) + stList.back();
        }
        else
            result += stList.back();
        
        if(idx < len) {
            result += s.substr(idx, len-idx);
        }

        // cout << "last: " << idx << endl;
        // cout << "result: " << result << endl;

        // result += s.substr(i, 0);

        if (answer == 0)
            answer = result.length();
        else if (answer > result.length())
            answer = result.length();
    }

    return answer;
}