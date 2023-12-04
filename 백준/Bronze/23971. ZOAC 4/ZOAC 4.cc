#include <iostream>

using namespace std;

int main() {
	
	int H, W, N, M;
	cin >> H >> W >> N >> M;

	int h_cnt = (H + N) / (N + 1);
	int w_cnt = (W + M) / (M + 1);

	cout << h_cnt * w_cnt;

}