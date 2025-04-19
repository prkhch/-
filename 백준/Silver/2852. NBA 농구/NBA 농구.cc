#include <bits/stdc++.h>

using namespace std;

int N, team, pre_sec, pre_win, m, s, sec_one, sec_two, scr_one, scr_two;
string now_sec;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> N;

    cin >> pre_win;
    cin >> now_sec;
    m = stoi(now_sec.substr(0, 2));
    s = stoi(now_sec.substr(3, 2));
    pre_sec = s + (m*60);
    if(pre_win == 1) scr_one++; // 1팀 득점
    else scr_two++; // 2팀 득점

    for(int i=1; i<N; i++) {
        cin >> team;
        cin >> now_sec;
        m = stoi(now_sec.substr(0, 2));
        s = stoi(now_sec.substr(3, 2));

        s += m*60; // 현재 득점 시간

        if(team == 1) scr_one++; // 1팀 득점
        else scr_two++; // 2팀 득점

        if(scr_one > scr_two) {
            if(pre_win == 1) {
                sec_one += s - pre_sec; // 계속 리드 중
            }
            pre_win = 1;
            pre_sec = s; // 리드 시작 또는 유지된 순간
        }
        else if(scr_one < scr_two) {
            if(pre_win == 2) {
                sec_two += s - pre_sec; // 계속 리드 중
            }
            pre_win = 2;
            pre_sec = s; // 리드 시작 또는 유지된 순간
        }
        else { // 동점 상태
            if(pre_win == 1) {
                sec_one += s - pre_sec;
            }
            else if(pre_win == 2) {
                sec_two += s - pre_sec;
            }
            pre_win = 0; // 현재 동점 상태
        }

    }

    if(scr_one > scr_two) {
        sec_one += 48*60 - pre_sec;
    } else if(scr_one < scr_two) {
        sec_two += 48*60 - pre_sec;
    }

    printf("%02d:%02d\n%02d:%02d", sec_one/60, sec_one%60, sec_two/60, sec_two%60);

}
