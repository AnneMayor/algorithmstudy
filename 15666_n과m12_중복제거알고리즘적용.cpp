#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m, inp[10], arr[10];
void f(int st, int cur) {
	if (m <= cur) {
		for (int i = 0; i < m; i++)printf("%d ", arr[i]); puts("");
	}
	else {
		for (int x = st; x < n; x++) {
			arr[cur] = inp[x];
			f(x, cur + 1);
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)scanf("%d", &inp[i]);
	sort(inp, inp + n);
	n = unique(inp, inp + n) - inp;
	f(0, 0);
}