function solution(numbers, n) {
   answer = 0;
   for(let v of numbers) {
       answer += v;
       if(answer > n) break;
   }
    
    return answer;
}