#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v[32001];
int inDegree[32001];
vector<int> edge[32001];
vector<int> result;

void topologySort() {
    priority_queue<int, vector<int>, greater<int>> pq; // 최소힙
    
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            pq.push(i);
        }
    }

    while (pq.size()) {
        int now = pq.top();
        pq.pop();
        result.push_back(now);

        for (int i = 0; i < edge[now].size(); i++) {
            int adjNode = edge[now][i];
            inDegree[adjNode]--;
            if (inDegree[adjNode] == 0) {
                pq.push(adjNode);
            }
        }
    }

}

int main() {

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        inDegree[b] ++; // 진입 차수 입력
    }

    topologySort();

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
}