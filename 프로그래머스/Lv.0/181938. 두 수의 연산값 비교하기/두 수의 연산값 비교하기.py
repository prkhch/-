def solution(a, b):
    answer = 0
    
    s = str(a) + str(b)
    n = 2 * a * b
    
    if(int(s) >= n) :
        answer = int(s)
    else :
        answer = n
    
    return answer