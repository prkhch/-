#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int coin[21] = { 0, };
        int dp[10001] = { 0, };
        
        int n;
        cin >> n;
        
        for (int j = 1; j <= n; j++) {
            cin >> coin[j];
        }

        int target;
        cin >> target;

        dp[0] = 1;
        for (int j = 1; j <= n; j++) {
            for (int k = coin[j]; k <= target; k++) {
                dp[k] += dp[k - coin[j]];
            }
        }

        cout << dp[target] << "\n";
    }
}