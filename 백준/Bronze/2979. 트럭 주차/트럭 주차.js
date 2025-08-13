// https://pixx.tistory.com/85
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs
  .readFileSync(filePath)
  .toString()
  .split("\n")
  .map((v) => v.split(" ").map(Number));

let [A, B, C] = input.shift();

let arr = Array(101).fill(0);

for (const i of input) {
  for (let j = i[0]; j < i[1]; j++) {
    arr[j]++;
  }
}

let result = 0;
for (const i of arr) {
  result += i === 1 ? A : i === 2 ? 2 * B : i === 3 ? 3 * C : 0;
}

console.log(result);
