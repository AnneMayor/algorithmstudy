#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct segmentTree
{
    int n;
    vector<long long> pSum;

    segmentTree(const vector<long long> &array)
    {
        n = array.size();
        pSum.resize(n * 4);
        init(array, 0, n - 1, 1);
    }

    long long init(const vector<long long> &array, int left, int right, int node)
    {
        if (left == right)
            return pSum[node] = array[left];

        int mid = (left + right) / 2;
        long long leftSubTree = init(array, left, mid, node * 2);
        long long rightSubTree = init(array, mid + 1, right, node * 2 + 1);
        return pSum[node] = leftSubTree + rightSubTree;
    }

    long long query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        if (right < nodeLeft || nodeRight < left)
            return 0;

        if (left <= nodeLeft && nodeRight <= right)
            return pSum[node];

        int mid = (nodeLeft + nodeRight) / 2;
        return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
    }

    long long query(int left, int right)
    {
        return query(left - 1, right - 1, 1, 0, n - 1);
    }

    long long update(int index, int newValue, int node, int nodeLeft, int nodeRight)
    {

        if (index < nodeLeft || nodeRight < index)
            return pSum[node];

        if (nodeLeft == nodeRight)
            return pSum[node] = newValue;

        int mid = (nodeLeft + nodeRight) / 2;
        return pSum[node] = update(index, newValue, node * 2, nodeLeft, mid) + update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
    }

    long long update(int index, int newValue)
    {
        return update(index - 1, newValue, 1, 0, n - 1);
    }
};

int main(void)

{

    int n, q;
    scanf("%d %d", &n, &q);

    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &v[i]);

    segmentTree st(v);
    for (int i = 0; i < q; i++)
    {
        int x, y, a, b;
        scanf("%d %d %d %d", &x, &y, &a, &b);

        if (x > y)
            swap(x, y);

        printf("%lld\n", st.query(x, y));
        st.update(a, b);
        v[a - 1] = b;
    }

    return 0;
}