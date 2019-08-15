#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX = 1e5+5;

int v[105];
int w[MAX];

int d[105][MAX];

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		int w1, v1;
		scanf("%d %d", &w1, &v1);

		w[i] = w1;
		v[i] = v1;
	}

	memset(d, 0, sizeof(d));

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (w[i] <= j) {
				d[i][j] = max(d[i - 1][j], d[i - 1][j - w[i]] + v[i]);
			}
			else {
				d[i][j] = d[i - 1][j];
			}
		}
	}

	printf("%d\n", d[n][k]);

	return 0;
}