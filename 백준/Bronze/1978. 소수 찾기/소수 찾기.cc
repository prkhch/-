#include <iostream>

using namespace std;

int main() {

	int n; cin >> n;

	int num;
	int cnt = 0;
	bool is;
	for (int i = 0; i < n; i++) {
		is = false;
		cin >> num;
		if (num == 1) continue;
		for (int i = 2; i < num; i++) {
			if (num % i == 0) {
				is = true;
				break;
			}
		}
		if (is == false) cnt++;
	}

	cout << cnt;

}

