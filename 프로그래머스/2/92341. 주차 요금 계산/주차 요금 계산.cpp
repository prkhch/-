#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, int> time_map;
    map<string, int> cost_map;
    
    int final_time = (23 * 60) + 59;
    
    int records_size = records.size();
    for(int i=0; i<records_size; i++) {
        int hour = stoi(records[i].substr(0, 2));
        int minute = stoi(records[i].substr(3, 2));
        int parse_minute = (hour * 60) + minute;
        
        string key = records[i].substr(6, 4);
        
        // IN, ONU 판별 (IN 음수부호)
        parse_minute = (records[i].substr(11) == "IN") ? -parse_minute + final_time : parse_minute-final_time;
        
        time_map[key] += parse_minute;
    }
    
    // OKOKOKOKOKOKOKOKOKOKOKOKOKOKOKOKOK
    
    for(auto i : time_map) {
        //key =  i.first, time = i.second
        
        if ( i.second < fees[0]) { // 기본 시간
            cost_map[i.first] = fees[1]; // 기본 요금만
        } 
        else if( i.second >= fees[0]) { // 기본 시간보다 커서 단위 시간 포함 계산
            cost_map[i.first] = fees[1]; // 기본 요금 넣기            
            
            if( (i.second-fees[0]) % fees[2] != 0) { // 나머지가 있으면 올림처리
                cost_map[i.first] += (((i.second-fees[0]) / fees[2]) + 1) * fees[3];
            } else { // 나머지 없음
                cost_map[i.first] += ((i.second-fees[0]) / fees[2]) * fees[3];
            }
        }
        
        answer.push_back(cost_map[i.first]);
    }
    
    
    return answer;
}