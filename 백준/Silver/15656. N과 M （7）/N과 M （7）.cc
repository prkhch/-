#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

void run(int arr[], vector<int> v) {
	
	int v_size = v.size();
	if (v_size == M) {
		for (int i = 0; i < M; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		v.push_back(arr[i]);
		run(arr, v);
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
	run(arr, v);

}
