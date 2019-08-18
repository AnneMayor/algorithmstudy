#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;
const int MAX = 100005;

stack<int> s;
vector<char> sign;
bool isChecked[MAX];

int main()
{

    int n;
    scanf("%d", &n);

    while(!s.empty()) {
        s.pop();
    }
    
    memset(isChecked, false, sizeof(isChecked));
    sign.clear();

    int nums[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    bool flag = true;

    for (int num = 1; num <= nums[0]; num++)
    {
        s.push(num);
        sign.push_back('+');
        isChecked[num] = true;
    }

    for (int i = 0; i < n; i++)
    {
        if(s.empty()) {

            for (int cnt = 1; cnt <= nums[i]; cnt++)
            {
                if(!isChecked[cnt]) {
                    s.push(cnt);
                    sign.push_back('+');
                    isChecked[cnt] = true;
                }
                
            }
            s.pop();
            sign.push_back('-');
        } else if (s.top() == nums[i])
        {
            s.pop();
            sign.push_back('-');
        }
        else if (s.top() < nums[i])
        {
            for (int cnt = s.top() + 1; cnt <= nums[i]; cnt++)
            {
                if (!isChecked[cnt])
                {
                    s.push(cnt);
                    sign.push_back('+');
                    isChecked[cnt] = true;
                }
            }
            s.pop();
            sign.push_back('-');
        }
        else if (s.top() > nums[i])
        {
            flag = false;
            break;
        }
    }

    if (!flag)
    {
        printf("NO\n");
    }
    else
    {
        for (int i = 0; i < sign.size(); i++)
        {
            printf("%c\n", sign[i]);
        }
    }

    return 0;
}