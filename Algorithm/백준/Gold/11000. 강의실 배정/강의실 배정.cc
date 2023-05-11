#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int, int>> v; // 강의실
priority_queue<int, vector<int>, greater<int> > pq; // 우선순위 큐

int n;
int st, ed;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> st >> ed;
		v.push_back(make_pair(st, ed));
	}

	sort(v.begin(), v.end()); // 강의 시작시간 기준 정렬

	pq.push(v[0].second); // 첫번째 강의에 끝나는 시간 큐에 넣기

	for (int i = 1; i < n; i++) {

		if (pq.top() > v[i].first) { // 강의 시간이 겹치면
			pq.push(v[i].second); // 강의실 추가
		}
		else if (pq.top() <= v[i].first) { // 강의 시간 안겹치면
			// 강의실 합치기
			pq.pop();
			pq.push(v[i].second); 
		}
	}
	cout << pq.size();
}