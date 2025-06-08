#include <bits/stdc++.h> 
using namespace std;

int N, row[24];
int mn = 987654321;

void go(int now) {
	if (now == N+1) {
		int sum = 0;

		for (int i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = 1; j <= N; j++) {
				if (row[j] & (1 << i)) cnt++;
			}
			sum += min(cnt, N - cnt);
		}
		mn = min(mn, sum);
		return;
	}


	go(now + 1);
	row[now] = ~row[now];
	go(now + 1);

}

int main() {

	cin >> N;
	string str;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			if (str[j] == 'T') {
				row[i] |= (1 << j);
			}
		}
	}

	go(1);

	cout << mn;

}