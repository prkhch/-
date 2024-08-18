function solution(array) {
    
    let answer = [array[0], 0];
    
    array.forEach((v, i) => {
        if(answer[0] < v) {
            answer[0] = v;
            answer[1] = i;
        }
    })
    
    return answer;
}