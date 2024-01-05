#include <iostream>
#include <cmath>

using namespace std;

int decimal[1000001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int M; int N;
	cin >> M >> N;

	decimal[1] = 1;
	for (int i = 2; i <= sqrt(N); i++) {
		if (decimal[i] == 1) continue;
		for (int j = i * 2; j <= N; j += i) {
			decimal[j] = 1;
		}
	}

	for (int i = M; i <= N; i++) {
		if (decimal[i] == 0) {
			cout << i << "\n";
		}
	}

}
