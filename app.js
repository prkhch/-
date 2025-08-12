// https://pixx.tistory.com/85
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().split("\n");

const used = Array(9).fill(false);
const result = [];

function search(st, count, sum) {
  if (count === 7) {
    if (sum === 100) {
      result.sort((a, b) => a - b);
      for (const x of result) {
        console.log(x);
      }
      process.exit(0);
    }
    return;
  }
  for (let i = st; i < 9; i++) {
    if (used[i]) continue;
    used[i] = true;
    result.push(input[i]);
    search(i + 1, count + 1, sum + Number(input[i]));
    used[i] = false;
    result.pop();
  }
}

search(0, 0, 0);
