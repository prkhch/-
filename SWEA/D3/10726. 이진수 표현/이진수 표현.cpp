#include <iostream>
#include <string>
#include <bitset>
using namespace std;

// m의 이진수를 직접 구하지 않고, '&'연산을 통해 조건 확인 가능

int main() {

	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++) {
		int n, m;
		cin >> n >> m;

		if ( (m & ((1 << n) - 1)) == ((1 << n) - 1) ) {
			cout << '#' << i << ' ' << "ON" << "\n";
		}
		else {
			cout << '#' << i << ' ' << "OFF" << "\n";
		}
	}

}