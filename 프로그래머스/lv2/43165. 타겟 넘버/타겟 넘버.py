cnt = 0

def run(numbers, target, lv, res) :
    global cnt
    
    if(len(numbers)==lv) :
        if(res==target) :
            cnt += 1
            
        return
        
    run(numbers, target, lv+1, res + numbers[lv])
    run(numbers, target, lv+1, res - numbers[lv])
    
def solution(numbers, target):
    answer = 0
    run(numbers, target, 0, 0)
    
    answer = cnt
    
    return answer