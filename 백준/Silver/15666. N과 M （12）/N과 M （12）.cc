#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[9];
int result[9];

void run(int lv, int idx) {

	if (lv == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	int before = 0;
	for (int i = idx; i < N; i++) {
		if (before == arr[i]) continue;
		before = arr[i];
		result[lv] = arr[i];
		run(lv+1, i);
	}

	// 1 7 9 9
}

int main() {
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	run(0, 0);

}
