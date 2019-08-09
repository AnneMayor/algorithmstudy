#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
const int MAX = 10;

int n, m;
int nums[MAX];
vector<int> numList;
set<string> group;

bool duplicate() {
	string tmp = "";
	int len = numList.size();
	for (int i = 0; i < len; i++) {
		tmp += numList[i] + '0';
	}

	if (group.find(tmp) == group.end()) {
		group.insert(tmp);
		return false;
	}
	else {
		return true;
	}
}

void recursive(int cnt) {

	if (cnt > m) return;
	if (cnt == m) {
		if (!duplicate()) {
			int len = numList.size();
			for (int i = 0; i < len; i++) {
				printf("%d ", numList[i]);
			}
			printf("\n");
		}
	}

	for (int i = 0; i < n; i++) {
		numList.push_back(nums[i]);
		recursive(cnt + 1);
		numList.pop_back();
	}
}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}

	sort(nums, nums + n);

	for (int i = 0; i < n; i++) {
		numList.push_back(nums[i]);
		recursive(1);
		numList.pop_back();
	}

	return 0;
}