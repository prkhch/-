function solution(my_string) {
    let answer = 0;
    
    [...my_string].map(i => isNaN(i) ? null : answer+=Number(i));
    
    return answer;
}