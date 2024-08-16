function solution(n) {
    let answer = 2;
    
    for(let i=0; i<=1000; i++) {
        if(i*i === n) answer = 1;
    }
    
    return answer;
}