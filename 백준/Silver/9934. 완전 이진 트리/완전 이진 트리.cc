#include <bits/stdc++.h>
using namespace std;

int K, arr[1024];
vector<vector<int>> v;

void dfs(int l, int r, int lv) {

	if (lv >= K) {
		return;
	}
	int mid = (l + r) / 2;
	v[lv].push_back(arr[mid]);
	dfs(l, mid-1, lv + 1);
	dfs(mid+1, r, lv + 1);

}

int main() {

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> K;
	v.resize(K);
	int size = pow(2, K) - 1;
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	dfs(0, size, 0);

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}

}


