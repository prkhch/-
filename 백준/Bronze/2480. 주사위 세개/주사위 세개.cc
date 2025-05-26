#include <bits/stdc++.h>
using namespace std;

int n, mx, dice[7];

int main() {

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 3; i++) {
		cin >> n;
		dice[n] += 1;
		mx = max(mx, dice[n]);
	}

	if (mx == 1) {
		for (int i = 6; i >= 1; i--) {
			if (dice[i]) {
				cout << i * 100;
				break;
			}
		}
	}
	else if (mx == 2) {
		for (int i = 6; i >= 1; i--) {
			if (dice[i] == 2) {
				cout << 1000 + (i * 100);
				break;
			}
		}
	}
	else if (mx == 3) {
		for (int i = 6; i >= 1; i--) {
			if (dice[i] == 3) {
				cout << 10000 + (i * 1000);
				break;
			}
		}
	}

}