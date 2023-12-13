#include <iostream>

using namespace std;

int main() {

	for (int i = 0; i < 3; i++) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1) cnt++;
		}
		if (cnt == 1) cout << 'C' << "\n";
		else if (cnt == 2) cout << 'B' << "\n";
		else if (cnt == 3) cout << 'A' << "\n";
		else if (cnt == 4) cout << 'E' << "\n";
		else if (cnt == 0) cout << 'D' << "\n";
	}
}
