def solution(numbers, target):
    global c
    answer = 0
    dfs(0,0,numbers,target)
    answer = c
        
    return answer
c = 0
def dfs(lev,Sum,lst,num):
    global c
    if lev == len(lst):
        if Sum == num:
            c += 1
        return
    for i in range(2):
        if i ==1:
            dfs(lev+1,Sum+lst[lev],lst,num)
        else:
            dfs(lev+1,Sum-lst[lev],lst,num)