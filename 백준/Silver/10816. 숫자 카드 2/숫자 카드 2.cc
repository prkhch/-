#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
map<int, int> dict;
int arr[500001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int key;
		cin >> key;
		dict[key] ++;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int req;
		cin >> req;
		if (dict[req]) {
			cout << dict[req] << " ";
		}
		else {
			cout << 0 << " ";
		}
	}

}