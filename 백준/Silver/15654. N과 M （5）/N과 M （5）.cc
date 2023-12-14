#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N, M;

void run(int arr[], bool used[], vector<int> v) {

	int v_size = v.size();
	if (v_size == M) {
		for (int i = 0; i < v_size; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		if (used[i] == true) continue;
		v.push_back(arr[i]);
		used[i] = true;
		run(arr, used, v);
		v.pop_back();
		used[i] = false;
	}

} 

int main() {

	int arr[9];
	bool used[9];
	memset(arr, 0, sizeof(arr));
	memset(used, false, sizeof(used));

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int num; 
		cin >> num;
		arr[i] = num;
	}

	sort(arr, arr+N);

	vector<int> v;

	run(arr, used, v);

}
