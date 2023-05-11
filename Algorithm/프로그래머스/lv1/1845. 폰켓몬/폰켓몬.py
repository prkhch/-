from collections import Counter

def solution(nums):
    answer = 0
    
    n = len(nums)
    c = Counter(nums)
    if n//2 <= len(c):
        answer = n//2
    elif n//2 > len(c):
        answer = len(c)
    
    return answer