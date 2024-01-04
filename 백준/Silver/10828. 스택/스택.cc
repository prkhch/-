#include <iostream>
#include <stack>

using namespace std;

int main() {

	stack<int> st;
	int N;
	cin >> N;

	string command;
	int X;
	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "push") {
			cin >> X;
			st.push(X);
		}
		else if (command == "pop") {
			if (st.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (command == "size") {
			cout << st.size() << "\n";
		}
		else if (command == "empty") {
			if (st.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (command == "top") {
			if (st.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << st.top() << "\n";
			}
		}
	}
}
