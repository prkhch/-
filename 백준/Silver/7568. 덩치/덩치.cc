#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	int arr[51][2];
	int x; int y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arr[i][0] = x;
		arr[i][1] = y;
	}

	int rank;
	for (int i = 0; i < n; i++) {
		rank = 1;
		for (int j = 0; j < n; j++) {
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) {
				rank++;
			}
		}
		cout << rank << " ";
	}

}
