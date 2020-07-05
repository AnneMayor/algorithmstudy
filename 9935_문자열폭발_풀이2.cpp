#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{

    cin.tie(NULL);
    cout.tie(NULL);

    string sentence;
    string word;

    cin >> sentence >> word;
    stack<char> tail;
    int lenOfSentence = sentence.length();
    int lenOfWord = word.length();
    for (int i = lenOfSentence - 1; i >= 0; i--)
    {
        if (tail.size() >= lenOfWord)
        {
            string temp = "";
            while (temp.length() < lenOfWord)
            {
                char c = tail.top();
                tail.pop();
                temp += c;
            }

            int lenOfTemp = temp.length();
            if (temp != word)
            {
                for (int j = lenOfTemp - 1; j >= 0; j--)
                {
                    tail.push(temp.at(j));
                }
            }
        }

        tail.push(sentence.at(i));
    }

    if (tail.size() >= lenOfWord)
    {
        string temp = "";
        while (temp.length() < lenOfWord)
        {
            char c = tail.top();
            tail.pop();
            temp += c;
        }

        int lenOfTemp = temp.length();
        if (temp != word)
        {
            for (int j = lenOfTemp - 1; j >= 0; j--)
            {
                tail.push(temp.at(j));
            }
        }
    }

    if (tail.empty())
    {
        printf("FRULA\n");
        return 0;
    }

    string ans = "";

    while (!tail.empty())
    {
        char c = tail.top();
        tail.pop();
        ans += c;
    }

    cout << ans << endl;

    return 0;
}