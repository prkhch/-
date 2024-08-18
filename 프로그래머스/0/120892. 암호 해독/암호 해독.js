function solution(cipher, code) {
    let answer = '';
    
    [...cipher].map((v,i) => (i+1)%code === 0 ? answer+=v : null )
    
    return answer;
}