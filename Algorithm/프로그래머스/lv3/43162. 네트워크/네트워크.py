def dfs(node, n, computers, visit) :
    for i in range(n) :
        if node == i : continue
        if visit[i] == 1 : continue 
        if computers[node][i] == 1 : 
            visit[i] = 1
            dfs(i, n, computers, visit) 

def solution(n, computers):
    answer = 0
    visit = [0] * n
    
    for i in range(n) :
        if visit[i] == 0 :
            answer += 1
            visit[i] = 1
            dfs(i, n, computers, visit)
    
    return answer