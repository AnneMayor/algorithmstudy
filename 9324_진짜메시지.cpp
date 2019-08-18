#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 100001;

char str[MAX];
int cntOfChar[MAX];

int main() {

	int T;
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++) {
		scanf("%s", str);

		memset(cntOfChar, 0, sizeof(cntOfChar));

		int len = strlen(str);
		bool flag = true;
		int idx = 0;
		while (idx < len) 
		{
			cntOfChar[(int)str[idx] - 65] += 1;
			if (cntOfChar[(int)str[idx]-65] != 0 && cntOfChar[(int)str[idx] - 65] % 3 == 0) {
				cntOfChar[str[idx] - 65] = 0;
				if (str[idx] != str[idx + 1]) {
					flag = false;
					break;
				}
				else {
					idx += 2;
				}
			}
			else {
				idx++;
			}
		}

		for (int i = 0; i < len; i++) {
			if (cntOfChar[(int)str[i]-65] != 0&& cntOfChar[(int)str[i] - 65] % 3 == 0) {
				flag = false;
				break;
			}
		}

		if (flag) {
			printf("OK\n");
		}
		else {
			printf("FAKE\n");
		}

	}

	return 0;
}