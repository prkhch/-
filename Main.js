// 4
// https://pixx.tistory.com/85
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim();

for (let i = 0; i < input.length / 2; i++) {
  if (input.charAt(i) !== input.charAt(input.length - i - 1)) {
    console.log(0);
    process.exit(0);
  }
}

console.log(1);
