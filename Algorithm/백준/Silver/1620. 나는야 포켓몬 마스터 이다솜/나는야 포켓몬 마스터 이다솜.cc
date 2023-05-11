#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
map<int, string> num_dict;
map<string, int> name_dict;
vector<string> v;
string str;
string req; // 요청

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> str;
		num_dict[i] = str;
		name_dict[str] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> req;
		if (req[0] < 'A') { // 숫자면
			int numreq = stoi(req);
			cout << num_dict[numreq] << "\n";
		}
		else {
			cout << name_dict[req] << "\n";
		}
	}
	
}