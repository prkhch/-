#include <bits/stdc++.h>
using namespace std;

int X, N, sum;

int main() {

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> X >> N;

	int cst, cnt;
	for (int i = 0; i < N; i++) {
		cin >> cst >> cnt;
		sum += (cst * cnt);
	}

	cout << (sum == X ? "Yes" : "No");

}