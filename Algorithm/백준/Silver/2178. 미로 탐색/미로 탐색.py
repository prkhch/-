from collections import *

def bfs(y, x):
    d.append((y,x))

    while d :
        y, x = d.popleft()

        if y==n-1 and x==m-1 :
            return

        for i in range(4) :
            ny = dy[i] + y
            nx = dx[i] + x
            if 0 <= ny < n and 0 <= nx < m :
                if arr[ny][nx] == 1 :
                    arr[ny][nx] = arr[y][x] + 1
                    d.append((ny,nx))

n, m = map(int, input().split())
arr = [ list(map(int, input().strip())) for _ in range(n) ]
dy = [-1,1,0,0]
dx = [0,0,-1,1]

d = deque()
bfs(0, 0)
print(arr[n-1][m-1])