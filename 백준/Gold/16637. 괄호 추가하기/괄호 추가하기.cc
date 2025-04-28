#include <bits/stdc++.h>

using namespace std;

int N;
string s;
int mx = -987654321;

int cal(int a, char op, int b) {
    if(op=='+') {
        return a + b;
    } else if(op=='-') {
        return a - b;
    } else if (op=='*') {
        return a * b;
    }
}

void dfs(int sum, int pos) {
    if(pos >= N) {
        mx = max(mx, sum);
        return;
    }

    // 앞 괄호
    if(pos + 2 <= N) {
        dfs(cal(sum, s[pos], s[pos+1]-'0'), pos+2);
    }
    
    // 뒷 괄호
    if(pos + 4 <= N) {
        dfs(cal(sum, s[pos], cal(s[pos+1]-'0', s[pos+2], s[pos+3]-'0')), pos+4);
    }

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> s;
    dfs(s[0]-'0', 1);
    
    cout << mx;

}
