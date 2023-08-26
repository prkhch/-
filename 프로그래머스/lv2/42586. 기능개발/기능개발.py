from collections import deque
import math

dq = deque()

def solution(progresses, speeds):
    answer = []
    
    for i in range(len(progresses)) :
        dq.append(math.ceil((100 - progresses[i]) / speeds[i]))
    
    larger = dq.popleft()
    cnt = 1
    
    while (dq) :
        current = dq.popleft()
        if(larger >= current) :
            cnt += 1
        else :
            answer.append(cnt)
            larger = current
            cnt = 1
    
    # 남은 cnt 추가
    answer.append(cnt)
    
    
    # 같은 날짜는 카운트
    # 카운트 리턴
    
    
    return answer