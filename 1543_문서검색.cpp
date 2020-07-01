#include <iostream>
#include <string>

using namespace std;

int main()
{

    cin.tie(NULL);
    string sentence;
    string word;
    getline(cin, sentence);
    getline(cin, word);

    int lenOfSentence = sentence.length();
    int lenOfWord = word.length();
    int ans = 0;

    for (int i = 0; i < lenOfSentence;)
    {
        bool flag = true;
        for (int j = 0; j < lenOfWord; j++)
        {
            if (i + j >= lenOfSentence || sentence.at(i + j) != word.at(j))
            {
                i++;
                flag = false;
                break;
            }
        }

        if (flag)
        {
            i += lenOfWord;
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}