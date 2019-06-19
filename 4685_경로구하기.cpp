#include <iostream>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;
const int MAX = 1005;

int Prev[MAX];
int n, k;
queue<int> q;
stack<int> st;

int nums[MAX][MAX];
int cntOfStep[MAX];

bool isHammingDistance(int num1[], int num2[])
{
    bool flag = true;

    int cntOfDiff = 0;

    // cout << "num1: ";
    // for(int i = 0; i < k; i++) {
    //     cout << num1[i];
    // }
    // cout << endl;

    // cout << "num2: ";
    // for(int i = 0; i < k; i++) {
    //     cout << num2[i];
    // }
    // cout << endl;

    for (int i = 0; i < k; i++)
    {
        if (cntOfDiff > 1)
        {
            flag = false;
            break;
        }

        if (num1[i] != num2[i])
            cntOfDiff += 1;
    }

    if (cntOfDiff > 1)
        flag = false;

    // cout << "flag: " << flag << endl;

    return flag;
}

void findAns(int start)
{
    q.push(start);
    cntOfStep[start] = 1;

    while (!q.empty()) {
        int idx = q.front();
        int step = cntOfStep[idx];
        q.pop();

        for(int i = 1; i <= n; i++) {
            if(Prev[i] == 0 && isHammingDistance(nums[i], nums[idx])) {
                cntOfStep[i] = step+1;
                Prev[i] = idx;
                q.push(i);
            }

            if(Prev[i] != 0 && isHammingDistance(nums[i], nums[idx])) {
                if(cntOfStep[i] > step+1) {
                    cntOfStep[i] = step+1;
                    Prev[i] = idx;
                    q.push(i);
                }
            }
        }
    }
    
}

int main()
{

    memset(Prev, 0, sizeof(Prev));
    memset(cntOfStep, 0, sizeof(cntOfStep));

    scanf("%d %d", &n, &k);

    int temp[k];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%1d", &temp[j]);
        }

        for (int j = 0; j < k; j++)
        {
            nums[i][j] = temp[j];
        }
    }

    int s, e;
    scanf("%d %d", &s, &e);

    Prev[s] = s;
    findAns(s);

    if (Prev[e] == 0)
    {
        printf("-1\n");
    }
    else
    {
        for(int i = e; i != s; i = Prev[i]) st.push(i);
        st.push(s);

        while(!st.empty()) {
            printf("%d ", st.top());
            st.pop();
        }
        
        printf("\n");
    }

    return 0;
}