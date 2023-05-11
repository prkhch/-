#include <iostream>
#include <string>
using namespace std;

int n;
int m;
int edges[101][101];

int st;
int ed;
int cost;
int inf = 21e7;

int main()
{
	cin >> n; // 도시의 개수
	cin >> m; // 버스의 개수

	// 초기 조건(최댓값) 설정
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			edges[i][j] = inf; // 비용은 100,000보다 작거나 같다.
		}
	}

	// 비용 설정
	for (int i = 0; i < m; i++) {
		cin >> st; // 시작
		cin >> ed;
		cin >> cost;

		if (edges[st][ed] > cost) {
			edges[st][ed] = cost;
		}
	}

	// 플로이드-워셜
	for (int k = 1; k <= n; k++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				if (s == e) { edges[s][e] = 0; continue; } // 자기 자신에게 가는 비용은 0이다.
				if (edges[s][e] > edges[s][k] + edges[k][e]) {
					edges[s][e] = edges[s][k] + edges[k][e];
				}
			}
		}
	}

	// 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (edges[i][j] == inf) {
				cout << 0 << " ";
			}
			else {
				cout << edges[i][j] << " ";
			}
		}
		cout << "\n";
	}

}
