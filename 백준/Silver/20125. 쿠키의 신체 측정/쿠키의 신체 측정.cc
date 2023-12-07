#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int N;
	cin >> N;
	
	vector<string> arr(N);
	string line;

	for (int i = 0; i < N; i++) {
		cin >> line;
		arr[i] = line;
	}

	//
	int heart_x, heart_y;
	bool find_head = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == '*') {
				heart_x = j;
				heart_y = i+1;
				find_head = true;
				break;
			}
		}
		if (find_head) break;
	}

	int left_arm = 0;
	for (int i = heart_x - 1; i >= 0; i--) {
		if (arr[heart_y][i] == '*') {
			left_arm++;
		}
		else break;
	}

	int right_arm = 0;
	for (int i = heart_x + 1; i < N; i++) {
		if (arr[heart_y][i] == '*') {
			right_arm++;
		}
		else break;
	}

	int core = 0;
	for (int i = heart_y + 1; i < N; i++) {
		if (arr[i][heart_x] == '*') {
			core++;
		}
		else break;
	}

	int left_leg = 0;
	for (int i = heart_y + core + 1; i < N; i++) {
		if (arr[i][heart_x-1] == '*') {
			left_leg++;
		}
		else break;
	}

	int right_leg = 0;
	for (int i = heart_y + core + 1; i < N; i++) {
		if (arr[i][heart_x + 1] == '*') {
			right_leg++;
		}
		else break;
	}


	cout << heart_y + 1 << " " << heart_x + 1 << "\n";
	cout << left_arm << " " << right_arm << " " << core << " " << left_leg << " " << right_leg;

}