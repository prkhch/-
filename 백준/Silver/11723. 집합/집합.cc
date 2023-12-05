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

	int idxed = 0;
	int idx;
	string cmd;


	for (int i = 0; i < M; i++) {
		cin >> cmd;

		if (cmd != "all" && cmd != "empty") {
			cin >> idx;
		}

		// add
		if (cmd == "add") {
			idxed |= (1 << idx);
		}

		// remove
		else if (cmd == "remove") {
			idxed &= ~(1 << idx);
		}

 		// check
		else if (cmd == "check") {
			if (idxed & (1 << idx) ) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}

		// toggle
		else if (cmd == "toggle") {
			idxed ^= (1 << idx);
		}

		// all
		else if (cmd == "all") {
			idxed = (1 << 21) - 1;
		}

		// empty
		else if (cmd == "empty") {
			idxed = 0;
		}

	}

}