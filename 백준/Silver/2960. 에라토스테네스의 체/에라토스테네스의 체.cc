#include <iostream>
#include <cmath>
using namespace std;

int arr[1001];
int n, k;
int cnt;
int ans;

void eratosthenes() {
	for (int i = 2; i <= n + 1; i++) {
		for (int j = i; j <= n + 1; j += i) {
			if (arr[j] == 0) {
				continue;
			}
			arr[j] = 0; cnt++;
			if (cnt == k) {
				ans = j;
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	
	eratosthenes();
	cout << ans;

}