from collections import Counter

def solution(participant, completion):
    answer = ''
    p = Counter(participant)
    c = Counter(completion)

    p = p-c
    for k in p :
        answer = k

    return answer
