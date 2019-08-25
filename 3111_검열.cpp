#include <iostream>
#include <string>
#include <deque>

using namespace std;
const int MAX = 300000;

deque<char> l, r;

int main() {

    cin.tie(NULL); cout.tie(NULL);
    string word, text;
    cin >> word >> text;
    int start = 0;
    int end = text.length()-1;
    while (start <= end)
    {
        while (start <= end)
        {
            bool flag = false;
            l.push_back(text[start++]);
            if(l.size() >= word.length()) {
                flag = true;
                for(int i = 0; i < word.length(); i++) {
                    if(word[i] != l[l.size() - word.length()+i]) {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) {
                for (int i = 0; i < word.length(); i++)
                {
                    l.pop_back();
                }
                break;
            }
        }

        // cout << "start: " << start << " / end: " << end << endl;

        while (start <= end)
        {
            r.push_front(text[end--]);
            bool flag = false;
            if(r.size() >= word.length()) {
                flag = true;
                for(int i = 0; i < word.length(); i++) {
                    if(word[i] != r[i]) {
                        flag = false;
                        break;
                    }
                }
            }

            if(flag) {
                for(int i = 0; i < word.length(); i++) {
                    r.pop_front();
                }
                break;
            }
        }
    }

    string result = "";
    while (!l.empty())
    {
        char c = l.front();
        result += c;
        l.pop_front();
    }

    while (!r.empty())
    {
        char c = r.front();
        result += c;
        r.pop_front();
    }

    while (result.find(word) < MAX)
    {
        result.replace(result.find(word), word.length(), "");
    }
    
    cout << result << endl;

    return 0;
}