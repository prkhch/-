// 6
// https://pixx.tistory.com/85
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

const N = Number(input.shift());
const pattern = input.shift();
const [st, ed] = pattern.trim().split("*");
for (let i = 0; i < N; i++) {
  if (input.length < st.length + ed.length) {
    console.log("NE");
    continue;
  }

  if (
    st === input[i].substring(0, st.length) &&
    ed === input[i].substring(input[i].length - ed.length)
  ) {
    console.log("DA");
  } else {
    console.log("NE");
  }
}
