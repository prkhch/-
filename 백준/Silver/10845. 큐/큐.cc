#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	queue<int> q;

	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		if (str == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (str == "pop") {
			if (!q.size()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (str == "size") {
			cout << q.size() << "\n";
		}
		else if (str == "empty") {
			if (!q.size()) {
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (str == "front") {
			if (!q.size()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		else if (str == "back") {
			if (!q.size()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}
		
	}

}