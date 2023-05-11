def solution(citations):
    maxx = -21e8
    
    citations.sort(reverse=True)
    for i in range(citations[0]+1) :
        h = i
        y_cnt = 0
        n_cnt = 0
        for j in range(len(citations)) :
            if h <= citations[j] :
                y_cnt += 1
            else:
                n_cnt += 1
        if n_cnt <= h <= y_cnt :
            if maxx < h :
                maxx = h
    
    answer = maxx
    return answer