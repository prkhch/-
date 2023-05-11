#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;

int fac(int n) {

	if (n == 1 || n==0) {
		return 1;
	}

	return n * fac(n-1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	cout << fac(n) / (fac(k) * fac(n - k));

}