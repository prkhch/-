#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstring>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    // id_list -> number
    map<string, int> m;
    int id_list_size = id_list.size();
    for(int i=0; i<id_list_size; i++) {
        m[id_list[i]] = i;
    }
    

    // report_arr
    bool report_arr[id_list_size][id_list_size];
    memset(report_arr, 0, sizeof(report_arr));
    for(int i=0; i<report.size(); i++) {
        int tmp_idx = report[i].find(" ");
        int from = m[report[i].substr(0, tmp_idx)];
        int to = m[report[i].substr(tmp_idx+1)];
        report_arr[from][to] = true;
    }
    
    // cnt_arr
    int cnt_arr[id_list_size];
    memset(cnt_arr, 0, sizeof(cnt_arr));
    for(int i=0; i<id_list_size; i++) {
        for(int j=0; j<id_list_size; j++) {
            if(report_arr[i][j]==true) {
                cnt_arr[j]++;
            }
        }
    }
    
    for(int i=0; i<id_list_size; i++) {
        int mail_cnt = 0;
        for(int j=0; j<id_list_size; j++) {
            if(report_arr[i][j]==true) {
                if(cnt_arr[j] >= k) {
                    mail_cnt ++;
                }
            }
        }
        answer.push_back(mail_cnt);
    }
    
    
    return answer;
}