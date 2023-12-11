#include <iostream>

using namespace std;

bool eated[20001];
int cnt;

int main() {

	int N, K;
	string line;

	cin >> N >> K;
	cin >> line;

	for (int i = 0; i < N; i++) {

		if (eated[i] == true) continue;
		for (int j = i+1; j <= i+K; j++) {
			if (j >= N) break;
			if (eated[j] == true) continue;
			if (line[i] == line[j]) continue;
			eated[i] = eated[j] = true;
			cnt++; break;
		}
	}

	cout << cnt;
}
