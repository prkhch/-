#include <bits/stdc++.h>

using namespace std;

int H, W;
char arr[101][101];
int ret[101][101];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> H >> W;

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> arr[i][j];
        }
    }

    fill(&ret[0][0], &ret[0][0] + 101 * 101, -1);

    for(int i=0; i<H; i++) {
        int pos = -1;
        for(int j=0; j<W; j++) {
            if(arr[i][j] == 'c') {
                pos = j;
                ret[i][j] = 0;
            } else if(pos != -1) {
                ret[i][j] = j - pos;
            }
        }
    }

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cout << ret[i][j] << " ";
        }
        cout << "\n";
    }
}
