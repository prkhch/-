function solution(hp) {
    let answer = 0;
    
    let cnt = 0;
    
    if(hp>0 && hp % 5 === 0) {
        answer += hp/5;
         hp = 0;
    }
    
    if(hp > 5) {
        answer += Math.floor(hp/5);
        hp = hp%5;
    }
    
    if(hp>0 && hp % 3 === 0) {
        answer += hp/3;
        hp = 0;
    }
    
    if(hp > 3) {
        answer += Math.floor(hp/3);
        hp = hp%3;
    }
    
    answer += hp;
            
    return answer;
}