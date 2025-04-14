#include <bits/stdc++.h>

using namespace std;

int N, arr[65][65];
string tmp, ret;

void quad(int y, int x, int size) {
    if(size == 1) {
        ret += arr[y][x];
        return;
    }

    int fg = 1; // 같은 문자
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(arr[y][x] == arr[y + i][x + j]) continue;
            fg = 0;
            break;
        }
        if(fg==0) break;
    }

    if(!fg) {
        ret += "(";
        quad(y, x, size/2);
        quad(y, x + size/2, size/2);
        quad(y + size/2, x, size/2);
        quad(y + size/2, x + size/2, size/2);
        ret += ")";
    } else {
        ret += arr[y][x];
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> tmp;
        for(int j=0; j<N; j++) {
            arr[i][j] = tmp[j];
        }
    }

    quad(0, 0, N);

    cout << ret;

}
