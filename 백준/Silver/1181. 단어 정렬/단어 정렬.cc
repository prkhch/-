#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;

	string arr[20001];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++) {
		if (i > 0 && arr[i - 1] == arr[i]) {
			continue;
		}
		cout << arr[i] << "\n";
	}

}
