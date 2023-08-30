def solution(s):
    
    lst = list(map(int, s.split()))
    
    MAX = max(lst)
    MIN = min(lst)
    
    answer = ""
    answer += str(MIN)
    answer += " "
    answer += str(MAX)
    
    return answer