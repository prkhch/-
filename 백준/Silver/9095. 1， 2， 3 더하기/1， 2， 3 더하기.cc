#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt;

void run(int n, int sum) {

	if (n < sum) {
		return;
	}

	if (n == sum) {
		cnt++;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		run(n, sum + i);
	}
}

int main() {

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;

		cnt = 0;
		int sum = 0;
		run(n, sum);
		
		cout << cnt << "\n";
	}
}
