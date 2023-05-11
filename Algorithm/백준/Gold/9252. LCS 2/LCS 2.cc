#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
#define INF 1000000

int LCS[1001][1001];

int main() {

	string A;
	string B;

	cin >> A;
	cin >> B;

	for (int i = 1; i <= A.length(); i++) {
		for (int j = 1; j <= B.length(); j++) {
			if (A[i - 1] == B[j - 1]) {
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else {
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}

		}
	}

	int size = LCS[A.length()][B.length()];
	string str = "";

	int i = A.length();
	int j = B.length();
	while (i > 0 && j > 0) {
		if (LCS[i][j] == LCS[i - 1][j]) i--;
		else if (LCS[i][j] == LCS[i][j - 1]) j--;
		else {
			str += A[i - 1];
			i--; j--;
		}

	}
	

	if (size == 0) {
		cout << 0;
	}
	else {
		cout << size << "\n";
		for (int i = str.size()-1; i>=0; i--) {
			cout << str[i];
		}

	}
}