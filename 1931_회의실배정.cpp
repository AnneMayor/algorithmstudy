#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<long long int, long long int> > meeting;

int main() {

	int n;
	scanf("%d", &n);
	meeting.clear();

	for(int i = 0; i < n; i++) {
		long long int s, e;
		scanf("%lld %lld", &s, &e);
		meeting.push_back(make_pair(e, s));
	}

	sort(meeting.begin(), meeting.end());

	long long int start = meeting[0].first;
	int ans = 1;
	for(int i = 1; i < n; i++) {
		if(meeting[i].second < start) {
			meeting[i].first = -1;
		} else {
			ans += 1;
			start = meeting[i].first;
		}
	}

	printf("%d\n", ans);

	return 0;
}