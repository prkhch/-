#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	char arr[51][51] = { 0, };
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
		}
	}

	char b[8][8] = { 0, };
	char w[8][8] = { 0, };

	int order = 1;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (order % 2 == 1) {
				b[i][j] = 'B';
				w[i][j] = 'W';
			}
			else {
				b[i][j] = 'W';
				w[i][j] = 'B';
			}
			order++;
		}
		order++;
	}

	int min = 2501;
	int cnt;
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			cnt = 0;
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					if (arr[i + k][j + l] != b[k][l]) {
						cnt++;
					}
				}
			}
			if (cnt < min) min = cnt;
			cnt = 0;
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					if (arr[i + k][j + l] != w[k][l]) {
						cnt++;
					}
				}
			}
			if (cnt < min) min = cnt;
		}
	}
	cout << min;
}

