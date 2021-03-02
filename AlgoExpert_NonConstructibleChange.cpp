#include <vector>
#include <algorithm>

using namespace std;

int nonConstructibleChange(vector<int> coins) {
	sort(coins.begin(), coins.end());
	
	int change = 0;
	for(auto coin : coins) {
		if(coin > change+1) 
			return change+1;
		change += coin;
	}
	
  return change+1;
}
