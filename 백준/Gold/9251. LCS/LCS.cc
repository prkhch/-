#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int LCS[1001][1001]; // main() 안으로 넣으면 스택 크기가 부족하다고 나옴.

int main() {
	string A;
	string B;

	cin >> A;
	cin >> B;


	for (int i = 1; i <= A.length(); i++) {
		for (int j = 1; j <= B.length(); j++) {
			if (A[i - 1] == B[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
		}
	}

	cout << LCS[A.length()][B.length()];

}