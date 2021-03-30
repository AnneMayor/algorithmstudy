#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;

struct familyTree {

    int n;
    vector<int> tree;

    familyTree(const vector<int> & array) {
        n = array.size();
        tree.resize(n*4);
        init(array, 1, 0, n-1);
    }

    int init(const vector<int> & arr, int node, int start, int end) {
        if(start == end) return tree[node] = arr[start];
        int mid = (start+end) / 2;
        int leftMin = init(arr, node*2, start , mid);
        int rightMin = init(arr, node*2+1, mid+1, end);
        return tree[node] = min(leftMin, rightMin);
    }

    int query(int node, int left, int right, int nodeLeft, int nodeRight) {
        if(nodeLeft > right || nodeRight < left) return INT_MAX;
        if(left <= nodeLeft && nodeRight <= right) return tree[node];
        int mid = (nodeLeft+nodeRight) / 2;
        return min(query(node*2, left, right, nodeLeft, mid), query(node*2+1, left, right, mid+1, nodeRight));
    }

    int query(int start, int end) {
        return query(1, start, end, 0, n-1);
    }

    int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
        if(index < nodeLeft || nodeRight < index) return tree[node];
        if(nodeLeft == nodeRight) return tree[node] = newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return tree[node] = min(update(index, newValue, node*2, nodeLeft, mid), update(index, newValue, node*2+1, mid+1, nodeRight));
    }

    int update(int index, int newValue) {
        return update(index, newValue, 1, 0, n-1);
    }
};

vector<int> child[MAX];
int no2Serial[MAX], serial2no[MAX];
int locInTrip[MAX], depth[MAX];
int nextSerial;

void traverse(int here, int d, vector<int> & trip) {
    no2Serial[here] = nextSerial;
    serial2no[nextSerial] = here;
    nextSerial++;

    depth[here] = d;
    locInTrip[here] = trip.size();
    trip.push_back(no2Serial[here]);

    for(int i = 0; i < child[here].size(); i++) {
        traverse(child[here][i], d+1, trip);
        trip.push_back(no2Serial[here]);
    }
}

familyTree *prepareFamilyTree() {
    vector<int> trip;
    traverse(0, 0, trip);
    return new familyTree(trip);
}

int distance(familyTree *ft, int u, int v) {
    int lu = locInTrip[u], lv = locInTrip[v];
    if(lu > lv) swap(lu, lv);
    int lca = serial2no[ft->query(lu, lv)];
    return depth[u] + depth[v] - 2 * depth[lca];
}

int main(void) {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        for(int i = 0; i < MAX; i++)
            child[i].clear();

        int n, q;
        scanf("%d %d", &n, &q);

        for(int i = 1; i < n; i++) {
            int father;
            scanf("%d", &father);
            child[father].push_back(i);
        }

        nextSerial = 0;
        familyTree * ft = prepareFamilyTree();

        for(int i = 0; i < q; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d\n", distance(ft, a, b));
        }
    }


    return 0;
}