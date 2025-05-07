#include <bits/stdc++.h>

using namespace std;

int R, C, day, swanY, swanX, y, x, ny, nx;
bool isMeet;
char arr[1504][1504];
int dy[] = { -1, 0, 1, 0 }; 
int dx[] = { 0, 1, 0, -1 };
bool visited[1504][1504], v[1504][1504];
queue<pair<int, int>> contactList, swanList, tmp2, tmp;

void Qclear(queue<pair<int, int>>& q) {
	queue<pair<int, int>> empty;
	swap(q, empty);
}

void swanMove(queue<pair<int, int>>& tmp2) {

	while (swanList.size()) {
		tie(y, x) = swanList.front(); swanList.pop();

		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			if (arr[ny][nx] == 'X') {
				tmp2.push({ ny, nx });
			}
			if (arr[ny][nx] == '.') {
				swanList.push({ ny, nx });
			}
			if (arr[ny][nx] == 'L') {
				isMeet = 1;
				return;
			}
		}
	}
	
}


int main() {

	cin >> R >> C;
	string row;
	for (int i = 0; i < R; i++) {
		cin >> row;
		for (int j = 0; j < C; j++) {
			arr[i][j] = row[j];
			if (arr[i][j] == 'L') {
				swanY = i; swanX = j;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == '.' || arr[i][j] == 'L') {
				v[i][j] = 1;
				for (int k = 0; k < 4; k++) {
					ny = i + dy[k];
					nx = j + dx[k];
					if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
					if (arr[ny][nx] == 'X') {
						contactList.push({ ny, nx });
					}
				}
			}
		}
	}
	
	memset(visited, 0, sizeof(visited));
	swanList.push({ swanY, swanX });
	visited[swanY][swanX] = true;

	while (!isMeet) {
		swanMove(tmp2);
		if (isMeet) break;


		while (contactList.size()) {
			y, x;
			tie(y, x) = contactList.front(); contactList.pop();
			arr[y][x] = '.';

			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
				if (v[ny][nx]) continue;
				v[ny][nx] = 1;
				if (arr[ny][nx] == 'X') {
					tmp.push({ ny, nx });
				}
			}
		}

		contactList = tmp;
		swanList = tmp2;
		Qclear(tmp);
		Qclear(tmp2);
		day++;
	}

	cout << day;
}


