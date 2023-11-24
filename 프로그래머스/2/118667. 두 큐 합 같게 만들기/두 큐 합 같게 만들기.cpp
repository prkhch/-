#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long answer = -1;

    long long q1_sum=0; 
    long long q2_sum=0;
    queue<long long> q1;
    queue<long long> q2;
    
    long long q_size = queue1.size();
    for(long long i=0; i<q_size; i++) {
        q1.push(queue1[i]);
        q1_sum += queue1[i];
        q2.push(queue2[i]);
        q2_sum += queue2[i];
    }
    
    long long cnt = 0;
    long long tmp = 0;
    
    for(long long i=0; i<q_size*3; i++) {
        if(q1_sum > q2_sum) {
            tmp = q1.front();
            q1.pop();
            q1_sum -= tmp;
            q2.push(tmp);
            q2_sum += tmp;
            cnt++;
        } else if (q1_sum < q2_sum) {
            tmp = q2.front();
            q2.pop();
            q2_sum -= tmp;
            q1.push(tmp);
            q1_sum += tmp;
            cnt++;
        }

        if(q1_sum == q2_sum) {
            answer = cnt;
            break;
        }
    }
    
    return answer;
}