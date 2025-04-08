#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    
    int arr[100001];
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    
    int psum[100001];
    memset(psum, 0, sizeof(psum));
    for(int i=1; i<N+1; i++) {
        psum[i] = psum[i-1] + arr[i-1];
    }
    
    
    int M, A, B;
    cin >> M;
    for(int i=0; i<M; i++) {
        cin >> A >> B;
        cout << psum[B] - psum[A-1] << "\n";
    }
    
}