def solution(land):
    
    N = len(land)
    
    dp = [[0 for j in range(4)] for i in range(2)]
    
    for i in range(4):
        dp[0][i] = land[0][i]
    
    for i in range(1, N):
        for j in range(4):
            maxx = 0
            for k in range(4):
                if j == k:
                    continue
                if maxx < dp[(i-1)%2][k]:
                    maxx = dp[(i-1)%2][k]
            dp[i%2][j] = land[i][j] + maxx
    
    answer = 0
    
    for i in range(4):
        if answer < dp[(N-1)%2][i]:
            answer = dp[(N-1)%2][i]
    return answer