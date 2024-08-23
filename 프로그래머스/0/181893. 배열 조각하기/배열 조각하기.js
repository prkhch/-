function solution(arr, query) {
    let start=0;
    let end;
    
    query.forEach((v, i) => i%2 == 0 ? end = start + v + 1 : start = start + v)
    
    return arr.slice(start, end);  
} 