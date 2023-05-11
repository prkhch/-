def solution(array, commands):
    answer = []
    for i in range(len(commands)) :
        tmp = []
        st, ed, k = commands[i][0], commands[i][1], commands[i][2]
        for j in range(st-1, ed) :
            tmp.append(array[j])
            tmp.sort()
        answer.append(tmp[k-1])
        
    return answer