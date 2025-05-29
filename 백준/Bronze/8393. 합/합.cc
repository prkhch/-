#include <bits/stdc++.h>
using namespace std;

int n, sum;

int main() {

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}

	cout << sum;

}