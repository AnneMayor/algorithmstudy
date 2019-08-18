#include <iostream>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		
		for(int j = n-1-i; j >= 0; j--) {
			printf(" ");
		}

		printf("*");

		if(i == n / 2) {
			for(int j = 0; j < 2*i-1; j++) {
				printf("*");
			}
		} else if(i != 0) {
			for(int j = 0; j < 2*i-1; j++) {
				printf(" ");
			}
		}

		if(i != 0) printf("*");

		for(int j = n-1-i; j >= 0; j--) {
			printf(" ");
		}

		printf("\n");

	}
	return 0;
}