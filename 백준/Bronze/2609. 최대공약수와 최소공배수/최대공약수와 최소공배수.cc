#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int a, b;
int tmp;

int gcm(int a, int b) {
	while (b > 0) {
		a = a % b;
		tmp = a;
		a = b;
		b = tmp;
	}

	return a;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a; cin >> b;

	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	cout << gcm(a, b) << "\n";
	cout << (a * b) / gcm(a, b) << "\n";

}