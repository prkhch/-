#include <iostream>
#include <string>

using namespace std;


int main() {

	int cnt = 1;
	string s;

	getline(cin, s);

	if (s.length() == 1 && s[0] == ' ') {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < s.length(); i++) {
		if (i == 0 && s[i] == ' ') continue;
		if (i == s.length()-1 && s[i] == ' ') continue;
		if (s[i] == ' ') cnt++;
	}

	cout << cnt;
}
