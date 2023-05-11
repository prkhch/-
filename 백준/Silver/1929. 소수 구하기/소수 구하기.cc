#include <iostream>
#include <cmath>
using namespace std;

int arr[1000001];
int m, n;

void eratosthenes() {
	for (int i = 2; i <= sqrt(n)+1; i++) {
		for (int j = i+i; j <= n; j += i) {
			arr[j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	
	for (int i = 2; i <= n; i++) {
		arr[i] = i;
	}
	
	eratosthenes();

	for (int i = m; i <= n; i++) {
		if (arr[i] != 0) {
			cout << arr[i] << "\n";
		}
	}

}