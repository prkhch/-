#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	int coin[101];
	
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	int dp[10001] = { 0, };

	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}

	cout << dp[k];

}