#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	priority_queue<int, vector<int>, greater<int> > pq;
	while (!pq.empty())
	{
		pq.pop();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			scanf("%d", &num);
			int pqSize = pq.size();
			if (pqSize < n) {
				pq.push(num);
			}
			else {
				if (pq.top() < num) {
					pq.pop();
					pq.push(num);
				}
			}
		}
	}

	printf("%d\n", pq.top());
	return 0;
}