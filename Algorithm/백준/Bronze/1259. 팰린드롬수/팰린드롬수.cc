#include<iostream>
#include<string>
using namespace std;

string n;

bool check(string n) {

	for (int i = 0; i < n.length() / 2; i++) {
		if (n[i] != n[n.length() - 1 - i]) {
			return false;
		}
	}
	return true;

}


int main() {

	while (1) {

		cin >> n;
		if (n == "0") {
			break;
		}

		if (check(n)) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}

	}
}
