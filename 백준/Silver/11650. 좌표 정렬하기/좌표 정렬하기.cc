#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> s1, pair<int, int> s2) {
	if (s1.first < s2.first) {
		return true;
	}
	else if (s1.first == s2.first) {
		if (s1.second < s2.second) {
			return true;
		}
	}
	return false;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<pair<int, int>> v;
	int n; cin >> n;

	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}

}

