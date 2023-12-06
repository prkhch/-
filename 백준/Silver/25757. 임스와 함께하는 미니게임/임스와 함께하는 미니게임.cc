#include <iostream>
#include <set>

using namespace std;

int main() {
	set<string> s;

	int N;
	char game;

	cin >> N;
	cin >> game;

	string player;
	for (int i = 0; i < N; i++) {
		cin >> player;
		s.insert(player);
	}

	int s_size = s.size();
	if (game == 'Y') {
		cout << s_size;
	}
	else if (game == 'F') {
		cout << s_size / 2;
	}
	else if (game == 'O') {
		cout << s_size / 3;
	}

}