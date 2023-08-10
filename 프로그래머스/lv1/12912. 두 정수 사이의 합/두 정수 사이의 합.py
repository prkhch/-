def solution(a, b):
    MIN = min(a,b)
    MAX = max(a,b)
    answer = 0
    for i in range(MIN, MAX+1) :
        answer += i
    return answer