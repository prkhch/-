#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> v;

bool cmp(string a, string b) {
    if(a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string str;

    cin >> N;

    for(int i=0; i<N; i++) {
        
        cin >> str;
        string buffer = "";
        for(char c : str) {
            if('0' <= c && c <= '9') {
                if(buffer == "0" && c == '0') {
                    continue;
                } 
                else if(buffer=="0" && c != '0'){
                    buffer = c;
                    continue;
                }
                buffer += c;
            } else if(buffer.size() > 0) {
                v.push_back(buffer);
                buffer = "";
            }
        }

        if(buffer.size() > 0) v.push_back(buffer);

    }

    sort(v.begin(), v.end(), cmp);

    for(string str : v) {
        cout << str << "\n";
    }

}
