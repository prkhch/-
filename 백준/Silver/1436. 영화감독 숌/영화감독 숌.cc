#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	int now = 0;
	int shom;
	string title;
	for (int i = 666; i <= 3000000; i++) {
		title = to_string(i);
		for (int j = 1; j < title.length() - 1; j++) {
			if (title[j] == '6' && title[j - 1] == '6' && title[j + 1] == '6') {
				now++;
				shom = i;
				break;
			}
		}
		if (n == now) {
			cout << shom;
			break;
		}

	}

}
