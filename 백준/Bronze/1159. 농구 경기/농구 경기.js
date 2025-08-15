// 5
// https://pixx.tistory.com/85
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().split("\n");

const N = input.shift();
let arr = Array(26).fill(0);

for (let i = 0; i < N; i++) {
  arr[input[i][0].charCodeAt(0) - 97]++;
}

let cnt = 0;
for (let i = 0; i < 26; i++) {
  if (arr[i] > 4) {
    process.stdout.write(String.fromCharCode(i + 97));
    cnt++;
  }
}

if (cnt === 0) console.log("PREDAJA");
