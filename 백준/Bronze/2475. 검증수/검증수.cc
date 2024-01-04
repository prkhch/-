#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int num;
	int res = 0;
	

	for (int i = 0; i < 5; i++) {
		cin >> num;
		res += pow(num, 2);
	}

	cout << res % 10;

}
