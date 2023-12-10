#include <iostream>

using namespace std;

int arr[250001];

int main() {
	
	int N, X;

	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int st = 0;
	int ed = X;
	
	int max=0, sum=0, cnt=1;

	for (int i = 0; i < X; i++) {
		max += arr[i];
	}
	sum = max;

	for (int i = 0; i < N-X; i++) {
		sum -= arr[st+i];
		sum += arr[ed+i];
		if (sum > max) {
			max = sum;
			cnt = 1;
		}
		else if (sum == max) {
			cnt++;
		}
	}

	if (max == 0) {
		cout << "SAD";
	}
	else {
		cout << max << "\n" << cnt << "\n";
	}
}
