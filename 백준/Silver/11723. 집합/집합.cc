#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[21];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		string cmd;
		cin >> cmd;

		int num;
		if (cmd != "all" && cmd != "empty") {
			cin >> num;
		}

		// add
		if (cmd == "add") {
			arr[num] = 1;
		}

		// remove
		else if (cmd == "remove") {
			arr[num] = 0;
		}

 		// check
		else if (cmd == "check") {
			if (arr[num] == 1) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}

		// toggle
		else if (cmd == "toggle") {
			if (arr[num] == 1) {
				arr[num] = 0;
			}
			else {
				arr[num] = 1;
			}
		}

		// all
		else if (cmd == "all") {
			for (int i = 1; i <= 20; i++) {
				arr[i] = 1;
			}
		}

		// empty
		else if (cmd == "empty") {
			for (int i = 1; i <= 20; i++) {
				arr[i] = 0;
			}
		}

	}

}