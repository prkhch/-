#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int t, k, n;
char cmd;
int pk[1000001]; // 삽입 순서

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t; // 테스트 케이스
	for (int i = 0; i < t; i++) {
		cin >> k; // k개의 연산
		priority_queue<pair<int, int>> max_heap; // 최대 힙
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap; // 최소 힙

		for(int j=0; j<k; j++) {
			cin >> cmd >> n;

			if (cmd == 'I') { // Insert
				max_heap.push(make_pair(n, j));
				min_heap.push(make_pair(n, j));
				pk[j] = 1;
			}

			else if (cmd == 'D') { // Delete
				if (n == 1) { // 최대 힙 
					while (!max_heap.empty()) {
						int x = max_heap.top().second;
						if (pk[x] == 0) { // 최소 힙에서 이미 pop 되었다,
							max_heap.pop();
						}
						else if (pk[x] == 1) { // 아직 처리 되지 않았다.
							pk[x] = 0;
							max_heap.pop();
							break;
						}
					}
				}
				else if (n == -1) { // 최소 힙 
					while (!min_heap.empty()) {
						int x = min_heap.top().second;
						if (pk[x] == 0) { // 최대 힙에서 이미 pop 되었다,
							min_heap.pop();
						}
						else if (pk[x] == 1) { // 아직 처리 되지 않았다.
							pk[x] = 0;
							min_heap.pop();
							break;
						}
					}
				}
			}

		} // 연산 종료

		// 남은 숫자 정리
		while (!max_heap.empty()) {
			int x = max_heap.top().second;
			if (pk[x] == 0) {
				max_heap.pop();
			}
			else if (pk[x] == 1) { // 가장 큰 수 살아있으면 break
				break;
			}
		}
		while (!min_heap.empty()) {
			int x = min_heap.top().second;
			if (pk[x] == 0) {
				min_heap.pop();
			}
			else if (pk[x] == 1) { // 가장 작은 수 살아있으면 break
				break;
			}
		}


		if (max_heap.empty() && min_heap.empty()) {
			cout << "EMPTY" << "\n";
		}
		else {
			cout << max_heap.top().first << " " << min_heap.top().first << "\n";
		}
	}

}