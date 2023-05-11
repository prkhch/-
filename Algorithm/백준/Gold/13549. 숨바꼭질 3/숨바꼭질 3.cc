#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 100000000
using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	vector<int> time(100001, INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push(make_pair(0, n));
	time[n] = 0;

	while (!pq.empty()) {
		int nowTime = pq.top().first;
		int nowX = pq.top().second; pq.pop();

		if (nowX == k) {
			break;
		}

		if (nowX * 2 < 100001 && time[nowX * 2] > nowTime) {
			time[nowX * 2] = nowTime;
			pq.push(make_pair(time[nowX * 2], nowX * 2));
		}

		if (nowX + 1 < 100001 && time[nowX + 1] > nowTime + 1) {
			time[nowX + 1] = nowTime + 1;
			pq.push(make_pair(time[nowX + 1], nowX + 1));
		}

		if (nowX - 1 >= 0 && time[nowX - 1] > nowTime + 1) {
			time[nowX - 1] = nowTime + 1;
			pq.push(make_pair(time[nowX - 1], nowX - 1));
		}


	}

	cout << time[k];

}