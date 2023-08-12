#include <iostream>
#include <string>

using namespace std;


int main() {
	int t;
	int n;
	cin >> t;
	for (int i = 1; i <= t; i ++) {
		int SWITCH = 0;
		int cnt = 0;
		cin >> n;

		while (SWITCH != 1023) {
			cnt += 1;
			int nn = n * cnt;
			while (nn > 0) {
				int digit = nn % 10;
				SWITCH |= 1 << digit;
				nn /= 10;
			}
		}
		
		cout << '#'<<i  << ' ' <<  cnt * n << '\n';
		
	}


}