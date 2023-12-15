#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int used[9];

void run(int lv, int idx, int arr[], vector<int> v) {
	
	if (lv == M) {
		for (int i = 0; i < M; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < N; i++) {
		v.push_back(arr[i]);
		run(lv+1, i, arr, v);
		v.pop_back();
	}
}

int main() {

	cin >> N >> M;

	int arr[9];
	memset(arr, 0, sizeof(arr));

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr[i] = num;
	}

	sort(arr, arr + N);
	vector<int> v;
	run(0, 0, arr, v);

}
