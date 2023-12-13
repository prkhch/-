#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int E, S, M;
	cin >> E >> S >> M;

	int a=0, b=0, c=0;
	int cnt = 0;

	while (1) {
		cnt++; a++; b++; c++;
		if (a == 16) {
			a = 1;
		}
		if (b == 29) {
			b = 1;
		}
		if (c == 20) {
			c = 1;
		}
		if (a == E && b == S && c == M) {
			break;
		}
	}
	cout << cnt;
}
