#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, m, a;
priority_queue<long, vector<long>, greater<long>> pq;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> a;
		pq.push(a);
	}

	for (int i = 0; i < m; i++) {
		long x = pq.top();
		pq.pop();
		long y = pq.top();
		pq.pop();
		pq.push(x + y);
		pq.push(x + y);
	}

	long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += pq.top();
		pq.pop();
	}

	cout << ans;

}