#include <bits/stdc++.h>

using namespace std;

int arr[101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int A, B, C;

    cin >> A >> B >> C;


    for(int i=0; i<3; i++) {
        int st, ed;
        cin >> st >> ed;
        for(int j=st; j<ed; j++) {
            arr[j]++;
        }
    }

    int sum = 0;
    for(int i=0; i<101; i++) {
        if(arr[i] == 1) {
            sum+=A;
        } else if(arr[i] == 2) {
            sum+=B*2;
        } else if(arr[i] == 3) {
            sum+=C*3;
        }
    }

    cout << sum;

}
