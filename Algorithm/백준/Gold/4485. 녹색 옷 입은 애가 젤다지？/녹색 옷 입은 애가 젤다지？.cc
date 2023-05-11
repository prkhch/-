#include<iostream>
#include<string>
#include<queue>
using namespace std;

int n;
int arr[126][126];
int dist[126][126];
int d[4][2] = { -1,0, 1,0, 0,-1, 0,1 };
// [-1,0]
// [1,0]
// [0,-1]
// [0,1]

int dijkstra() {
	priority_queue <pair<int, pair<int,int>>> pq; // <cost, <y,x>>
	pq.push(make_pair(-arr[0][0], make_pair(0, 0))); // (비용, (y,x))
	dist[0][0] = arr[0][0];

	while (!pq.empty()) {
		int cost = -pq.top().first; // pair.first : pair의 첫번째 인자 저장
		int y = pq.top().second.first; // pair.second.first : pair의 두번째 인자의 첫번째 인자 저장
		int x = pq.top().second.second; // pair.second.first : pair의 두번째 인자의 두번째 인자 저장
		pq.pop(); // 변수에 저장했으니 제거

		for (int i = 0; i < 4; i++) { // 델타
			int ny = y + d[i][0]; 
			int nx = x + d[i][1];
			if (0 <= nx && 0 <= ny && nx < n && ny < n) {
				int ncost = cost + arr[ny][nx]; // 좌표까지의 비용 = 이전비용 + 현재비용
				if (dist[ny][nx] > ncost) { // 더 적은 비용이라면
					dist[ny][nx] = ncost; // 최소비용 갱신
					pq.push(make_pair(-dist[ny][nx], make_pair(ny, nx))); // (현재 비용, (현재y, 현재x))
				}
			}
		}
	} // while 종료
	
	return dist[n - 1][n - 1]; // [n-1][n-1]까지의 (최소)비용
}

int main()
{
	int t_case = 1;
	while (1) {
		cin >> n;
		if (n == 0) { break; } // 0이 나오면 종료

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j]; // 배열 입력
				dist[i][j] = 21e8; // 최소 비용 갱신을 위한 초기값
			}
		}

		int res = dijkstra();
		cout << "Problem " << t_case++ << ": " << res << "\n";

	}
	
}