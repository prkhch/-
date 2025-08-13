// https://pixx.tistory.com/85
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString();

const result = Array(26).fill(0);

for (c of input) {
  result[c.charCodeAt(0) - 97]++;
}

for (i of result) {
  process.stdout.write(i + " ");
}
