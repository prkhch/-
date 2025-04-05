#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    int same = 0, diff = 0;
    char x = s[0];

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == x) same++;
        else diff++;

        if (same == diff) {
            answer++;
            same = 0;
            diff = 0;
            if (i + 1 < s.size()) {
                x = s[i + 1];
            }
        }
    }

    if (same != 0 || diff != 0) answer++;

    return answer;
}