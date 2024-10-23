using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = price;

    for(int i=2; i<=count; i++) {
        answer += price*i;
    }
    
    return answer-money > 0 ? answer-money : 0;
}