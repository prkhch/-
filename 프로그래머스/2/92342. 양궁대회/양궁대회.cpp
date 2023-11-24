#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int max_gap;
int max_arr[11];
bool imposible = true; 

void shot(int n, vector<int> info, int arr[], int lv, int apeach_score) {
    
    if(n < 0) { 
        return ;    
    }
    
    // 점수계산
    if(lv == 11) {
        int score = 0;
        for(int i=0; i<11; i++) {
            if(arr[i] > 0) {
                score += 10-i;
            }
        }
        
        int gap = score - apeach_score;
        if(gap <= 0) {
            return;
        }
        if(max_gap < gap) {
            max_gap = gap;
            for(int i=0; i<11; i++) {
                max_arr[i] = arr[i];
                imposible = false;
                if(n > 0) {
                    max_arr[10] += n;
                }
            }
        } else if(max_gap == gap) {
            for(int i=10; i>=0; i--) {
                if(max_arr[i] < arr[i]) {
                    for(int i=0; i<11; i++) {
                        max_arr[i] = arr[i];
                        imposible = false;
                        if(n > 0) {
                            max_arr[10] += n;
                        }
                    }
                    break;
                } else if(max_arr[i] == arr[i]) {
                    continue;
                } else {
                    break;
                }
            }
        }
        
        return;
    }
    
   
    int tmp_cnt = info[lv] + 1; // 어피치보다 1번 더 쏴
    arr[lv] = tmp_cnt; // 라이언 화살 개수 추가
    if(info[lv] > 0) { // lv과녁에 어피치 점수있으면
        apeach_score -= (10-lv); // 어피치 점수 무효
    }
    shot(n-tmp_cnt, info, arr, lv+1, apeach_score); // 다음 과녁
    
    // 안 쏘는 경우
    arr[lv] = 0; // lv과녁 화살 개수 0
    if(info[lv] > 0) {
        apeach_score += (10-lv); // 어피치 점수 복구
    }
    shot(n, info, arr, lv+1, apeach_score); // 다음 과녁
    
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    
    int apeach_score = 0;
    for(int i=0; i<11; i++) {
        if(info[i] > 0) {
            apeach_score += (10-i);
        }
    }
    
    int arr[11];
    memset(arr, 0, sizeof(arr));
    int lv = 0;
    shot(n, info, arr, lv, apeach_score);
    
    if(imposible) {
        answer.push_back(-1);        
    } else {
        for(int i=0; i<11; i++) {
            answer.push_back(max_arr[i]);
        }
    }

    
        
    return answer;
}