#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

priority_queue<pair<int, int>> jewels;
int N, K;

long long MaxValue(vector<int> &fbag)
{

    long long sum = 0;
    multiset<int> bag(fbag.begin(), fbag.end());

    for (int i = 0; i < N; i++)
    {

        if (bag.empty())
            return sum;

        int value = jewels.top().first;
        int weight = jewels.top().second;
        jewels.pop();

        // 오름차순으로 정렬된 가방 무게 중, 마지막에 위치한 가방 무게보다 현재 보석의 무게가 클 경우 넣을 가방 없음! 그래서 패스해준다!!
        // 이거 질문!
        if (*bag.rbegin() < weight)
            continue;
        else
        {
            bag.erase(bag.lower_bound(weight));
            sum += value;
        }
    }
    return sum;
}

int main(void)
{

    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
    {
        int M, V;
        scanf("%d %d", &M, &V);
        jewels.push(make_pair(V, M));
    }

    vector<int> bag(K);
    for (int i = 0; i < K; i++)
        scanf("%d", &bag[i]);
    long long ans = MaxValue(bag);
    printf("%lld\n", ans);

    return 0;
}
