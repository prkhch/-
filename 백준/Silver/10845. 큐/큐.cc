#include <iostream>
#include <queue>

using namespace std;

int main() {

	queue<int> q;

	int N;
	cin >> N;
	string cmd; int x;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> x;
			q.push(x);
		}
		else if (cmd == "pop") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (cmd == "size") {
			cout << q.size() << "\n";
		}
		else if (cmd == "empty") {
			if (q.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (cmd == "front") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}		
		else if (cmd == "back") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}
	}
}
