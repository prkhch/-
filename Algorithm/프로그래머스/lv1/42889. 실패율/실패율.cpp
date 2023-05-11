#include <string>
#include <vector>
using namespace std;

int stop[502];
double clear[502];
double fail[502];

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    for(int i=0; i<stages.size(); i++) { // 단순 도달 유저 수 저장
        stop[stages[i]] ++;
    }

    clear[N+1] = stop[N+1];
    for(int i=N; i>=0; i--) { // 모든 도달 유저 저장
        clear[i] = clear[i+1] + stop[i];        
    }

    for(int i=1; i<=N; i++) { // 실패율 저장
        if(stop[i]==0) {
            fail[i] = 0;
        }
        else {
            fail[i] = stop[i] / clear[i];
        }      
    }


    for(int i=1; i<=N; i++) {
        int max_idx = -1;
        double max_fail = -1;
        for(int j=N; j>=1; j--) { // 적은 번호의 스테이지가 앞으로
            if(fail[j] >= max_fail){
                max_fail = fail[j];
                max_idx = j;
            }
        }
        fail[max_idx] = -1;
        answer.push_back(max_idx);
    }


    return answer;
}