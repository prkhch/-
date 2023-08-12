#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int t_case = 1; t_case <= t; t_case++) {
		int n, m;
		cin >> n;
		cin >> m;

		int mask;
		mask = (1 << n) - 1;

		if (mask == (m & mask)) {
			cout << "#" << t_case << " ON" << "\n";
		}
		else {
			cout << "#" << t_case << " OFF" << "\n";
		}
	}
}
