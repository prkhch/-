function solution(num_list) {
    let answer = num_list.length >= 11 ? 0 : 1;
    
    num_list.length >= 11 ? num_list.forEach(v => answer += v) : num_list.forEach(v => answer *= v);
    
    return answer;
}