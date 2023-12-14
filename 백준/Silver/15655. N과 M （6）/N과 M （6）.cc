#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;

void run(int lv, int arr[], vector<int> v) {
	
	int v_size = v.size();
	if (v_size == M) {
		for (int i = 0; i < M; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}

	for (int i = lv; i < N; i++) {
		v.push_back(arr[i]);
		run(i+1, arr, v);
		v.pop_back();
	}

}

int main() {

	cin >> N >> M;

	int arr[9];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	vector<int> v;

	sort(arr, arr + N);
	run(0, arr, v);

}
