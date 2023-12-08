#include <iostream>

using namespace std;

int N, M;
int arr[7][7];
int result = 10000;

void run(int y, int x, int type, int cost) {
	cost += arr[y][x];
	int move[3] = { -1, 0, 1 };

	if (y == N) {
		if (result > cost) {
			result = cost;
		}
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (y > N - 1 || x > M - 1 || y < 0 || x < 0) continue;
		if (type == i) continue;

		run(y + 1, x + move[i], i, cost);
	}
}

int main() {
	
	cin >> N >> M;

	int input_num;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input_num;
			arr[i][j] = input_num;
		}
	}

	for (int i = 0; i < M; i++) {
		run(0, i, 3, 0);
	}

	cout << result;

}