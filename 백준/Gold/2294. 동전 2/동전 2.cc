#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
#define INF 1000000

int main() {

	int n, k;
	cin >> n >> k;

	int coin[101];
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	//sort(coin, coin + n + 1);

	int dp[100001] = { 0, };
	for (int i = 1; i <= k; i++) dp[i] = INF;

	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] == INF) {
		cout << -1;
	}
	else {
		cout << dp[k];
	}
}