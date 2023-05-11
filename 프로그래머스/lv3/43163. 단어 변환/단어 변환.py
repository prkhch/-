minn = 21e8
isPass = False

def check(st, ed) :
    cnt = 0
    for i in range(len(st)) :
        if st[i] == ed[i] :
            cnt += 1
    if cnt==len(st)-1 :
        return True
    else :
        return False

def dfs(lv, now, target, words, visit):
    global minn
    global isPass
    
    if now == target :
        if minn > lv :
            minn = lv
            isPass = True
        return
    
    if lv == len(words) :
        return
    
    for i in range(len(words)) :
        if visit[i] == 1 : continue
        if check(now, words[i]) :
            visit[i] = 1
            dfs(lv+1, words[i], target, words, visit)
            visit[i] = 0
        

def solution(begin, target, words):
    
    visit = [0] * len(words)
    
    for i in range(len(words)) :
        if check(begin, words[i]) :
            visit[i] = 1
            dfs(1, words[i] ,target, words, visit)
            visit[i] = 0
    
    if isPass == True :
        answer = minn
    else :
        answer = 0
    return answer