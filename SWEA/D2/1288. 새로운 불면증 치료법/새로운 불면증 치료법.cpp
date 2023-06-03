#include <iostream>
#include <string>
#include <bitset>
using namespace std;

// 각 자릿수에 숫자를 비트로 변경
// ex) 0은 1 << 0 == 1
// ex) 1은 1 << 1 == 10
// ex) 2은 1 << 2 == 100
// ex) 2은 1 << 3 == 1,000
// ex) 2은 1 << 4 == 10,000
// ex) 2은 1 << 5 == 100,000
// ex) 2은 1 << 6 == 1,000,000
// ex) 2은 1 << 7 == 10,000,000
// ex) 2은 1 << 8 == 100,000,000
// ex) 2은 1 << 9 == 1,000,000,000

// '|'를 통해 누적연산

int main() {

	int testCase;
	cin >> testCase;
	int goal = (1 << 10) - 1; // 1,111,111,111
	

	for (int i = 1; i <= testCase; i++) {
		int n;
		cin >> n;

		int visited = 0;
		int count = 1;
		while (1) {
			string str = to_string(n * count);
			for (char c : str) {
				int num = c - '0';
				visited = visited | (1 << num);
			}
			if (visited == goal) break;
			count++;
		}
		cout << '#' << i << " " << n * count << "\n";
	}
}