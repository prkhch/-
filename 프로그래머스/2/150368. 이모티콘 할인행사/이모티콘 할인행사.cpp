#include <string>
#include <vector>
#include <iostream>

using namespace std;
int max_plus_count;
int max_total_price;

void run(vector<vector<int>> users, vector<int> emoticons, int final_sales[], vector<int> sales) {
    if(sales.size() == emoticons.size()) {
        
        int plus_count = 0;
        int total_price = 0;
        
        for(int i=0; i<users.size(); i++) {
            int tmp_buy_money = 0;
            
            for(int j=0; j<emoticons.size(); j++) {
                if(users[i][0] <= sales[j]) { // 할인율 OK
                    tmp_buy_money += emoticons[j] * (100-sales[j]) * 0.01; // 구매액
                }   
            }
            
            if(tmp_buy_money >= users[i][1]) {
                plus_count ++; // 플러스 가입
            } else {
                total_price += tmp_buy_money;
            }  
           
        }
        
        if(plus_count > max_plus_count) { // 더 많은 가입 수
            max_plus_count = plus_count;
            max_total_price = total_price;
        } else if(plus_count == max_plus_count) { // 같을 때
            if(max_total_price < total_price) { // 더 많은 판매액
                max_total_price = total_price;
            }
        }
        return;
    }
    
    
    for(int i=0; i<4; i++) {
        sales.push_back(final_sales[i]);
        run(users, emoticons, final_sales, sales);
        sales.pop_back();
    }
    
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    int final_sales[4] =  {10, 20, 30, 40};
    
    vector<int> sales;
    
    run(users, emoticons, final_sales, sales);
    
    answer.push_back(max_plus_count);
    answer.push_back(max_total_price);
    return answer;
}