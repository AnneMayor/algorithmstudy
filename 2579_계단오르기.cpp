#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 305;

int d[MAX];
int nums[MAX];

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &nums[i]);
	}

	d[1] = nums[1];
	d[2] = nums[1] + nums[2];
	d[3] = max(nums[1] + nums[3], nums[2] + nums[3]);

	for (int i = 4; i <= n; i++) {
		d[i] = max(d[i - 2] + nums[i], d[i - 3] + nums[i - 1] + nums[i]);
	}

	printf("%d\n", d[n]);

	return 0;
}