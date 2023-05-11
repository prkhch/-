from collections import *
dy = [-1,1,0,0]
dx = [0,0,-1,1]
dq = deque()
isPass = False

def bfs(maps,n,m) :
    global isPass
    
    dq.append((0,0))
    
    while dq :
        y, x = dq.popleft()
        if y==n-1 and x==m-1 :
            isPass = True
            return
        
        for i in range(4) :
            ny = y + dy[i]
            nx = x + dx[i]
            if 0 <= ny < n and 0 <= nx < m :
                if maps[ny][nx] == 1 :
                    maps[ny][nx] = maps[y][x] + 1
                    dq.append((ny,nx))
          
def solution(maps):
    
    n = len(maps)
    m = len(maps[0])
    
    bfs(maps,n,m)
    if isPass == True :
        answer = maps[n-1][m-1]
    else :
        answer = -1
        
    return answer