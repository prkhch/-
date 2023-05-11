#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int n, m;
long arr[100001];
long tmp;

int check(long tmp) { // 이진 탐색
	int st = 0;
	int ed = n - 1;
	int mid;

	while (ed >= st) { // 시작점이 끝점보다 커질 때까지
		mid = (st + ed) / 2; // 이분
		if (arr[mid] == tmp) {
			return 1;
		}
		else if (arr[mid] > tmp) { // 
			ed = mid-1;
		}
		else if (arr[mid] < tmp) {
			st = mid+1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr+n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		cout << check(tmp) << "\n";
	}
	
	
}
