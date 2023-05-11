#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> stack;
    
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(') {
            stack.push(s[i]);
        } 
        else if(s[i]==')') { // 닫는 괄호인데
            if(!stack.empty()) { // 스택에 값이 있고
                if(stack.top()=='(') { // 맨위가 여는 괄호면
                    stack.pop(); // 괄호 제거
                }
            }
            else { // 스택에 값이 없으면
                answer=false; // 잘못된 괄호
                break;
            }
        }
    }
    
    if(!stack.empty()) { // 스택에 값이 있으면
        answer=false;
    }
    
    return answer;
}