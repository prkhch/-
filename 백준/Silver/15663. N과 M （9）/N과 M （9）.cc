#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[9];
int result[9];
bool used[9];

void run(int lv) {
	
	if (lv == M) {
		for (int i = 0; i < M; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	int before = 0;
	for (int i = 0; i < N; i++) {
		if (used[i] == true) continue;
		if (arr[i] == before) continue;
		result[lv] = arr[i];
		before = arr[i];
		used[i] = true;
		run(lv + 1);
		used[i] = false;
	}

}

int main() {
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	run(0);

}
