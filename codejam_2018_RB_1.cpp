#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define pii pair<int, int>

using namespace std;

int main()
{

    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        int n, l;
        scanf("%d %d", &n, &l);
        vector<int> numOfLanguageSelected(n);
        int ans = 0;
        int curPeopleSelected = 0;
        int add = 100 % n;
        int middle = (n + 1) / 2;
        for (int i = 0; i < l; i++)
        {
            scanf("%d", &numOfLanguageSelected[i]);
            curPeopleSelected += numOfLanguageSelected[i];
        }

        int remainder = n - curPeopleSelected;
        for(int i = 0; i < remainder; i++) {
            numOfLanguageSelected.push_back(0);
        }

        vector<pii> totalNumOfPeople;
        for(int i = 0; i < n; i++) {
            int addFlag = (numOfLanguageSelected[i] * 100) % n;
            totalNumOfPeople.push_back(make_pair(addFlag, numOfLanguageSelected[i]));
        }

        sort(totalNumOfPeople.begin(), totalNumOfPeople.end(), greater<pii>());

        for(int i = 0; i < n; i++) {
            while (remainder && totalNumOfPeople[i].first < middle && totalNumOfPeople[i].first + add < n )
            {
                totalNumOfPeople[i].first += add;
                totalNumOfPeople[i].second++;
                remainder--;
            }
        }

        for(int i = 0; i < n; i++) {
            double temp = (double) totalNumOfPeople[i].second / (double) n;
            temp *= 100;
            ans += round(temp);
        }

        printf("Case #%d: %d\n", tc, ans);
    }

    return 0;
}