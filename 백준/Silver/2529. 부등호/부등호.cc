#include <bits/stdc++.h>
using namespace std;

int k, visited[10];
char arr[9];
vector<int> result;
long long mn = 9876543210, mx = 0;
string mns, mxs;

bool cmp(char c, int pre, int post) {
	if (c == '<' && pre < post) return true;
	if (c == '>' && pre > post) return true;
	return false;
}

void dfs(int lv) {

	if (lv > k) {
		string tmp = "";
		for (int i = 0; i < result.size(); i++) {
			tmp += to_string(result[i]);
		}
		if (mn > stoll(tmp)) {
			mns = tmp;
			mn = stoll(tmp);
		}
		if (mx < stoll(tmp)) {
			mxs = tmp;
			mx = stoll(tmp);
		}
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (visited[i]) continue;
		if (lv == 0) result.push_back(i);
		else {
			if (cmp(arr[lv - 1], result[lv - 1], i)) {
				result.push_back(i);
			}
			else continue;
		}
		visited[i] = 1;
		dfs(lv + 1);
		visited[i] = 0;
		result.pop_back();
	}


}

int main() {

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}

	dfs(0);

	cout << mxs << "\n" << mns;


}


