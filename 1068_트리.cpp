#include <iostream>
#include <vector>

using namespace std;

const int MAX = 55;

int N, deleteNode;
pair<int, bool> parent[MAX]; //부모노드, (true: leaf가 아니다, false: leaf)
vector<int> ancestor[MAX];

int countLeaf()
{
    //조상 중에 deleteNode가 있으면 삭제된 노드이므로
    for (int i = 0; i < N; i++)
        for (int j = 0; j < ancestor[i].size(); j++)
            if (ancestor[i][j] == deleteNode)
                parent[i].second = true; //leaf가 아니다

    //삭제된 노드 제외하고 다시 자식 여부 파악
    for (int i = 0; i < N; i++)
        if (i != deleteNode)
            parent[parent[i].first].second = true; //leaf가 아니다

    //leaf 노드 개수 센다
    int cnt = 0;
    for (int i = 0; i < N; i++)
        if (parent[i].second == false)
            cnt++;

    return cnt;
}

int main(void)

{

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int parentNode;
        scanf("%d", &parentNode);
        parent[i].first = parentNode;
        if(parent[i].first != -1) parent[parent[i].first].second = true;
        else parent[i].second = true;
    }

    //모든 조상 파악
    for (int i = 0; i < N; i++)
    {
        int curParent = parent[i].first;

        while (curParent != -1)
        {
            ancestor[i].push_back(curParent);
            curParent = parent[curParent].first;
        }
    }

    scanf("%d", &deleteNode);
    parent[deleteNode].second = true; //삭제된 노드는 leaf에서 제외
    parent[parent[deleteNode].first].second = false; //삭제된 노드 부모는 leaf

    printf("%d\n", countLeaf());

    return 0;
}