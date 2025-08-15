// 6
// https://pixx.tistory.com/85
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().split("\n");

let answer = "";
for (let i = 0; i < input[0].length; i++) answer += solution(input[0][i]);

console.log(answer);

function solution(char) {
  if (97 <= char.charCodeAt(0) && char.charCodeAt(0) <= 97 + 25) {
    if (char.charCodeAt(0) + 13 > 97 + 25)
      return String.fromCharCode(char.charCodeAt(0) + 13 - 26);
    else return String.fromCharCode(char.charCodeAt(0) + 13);
  } else if (65 <= char.charCodeAt(0) && char.charCodeAt(0) <= 65 + 25) {
    if (char.charCodeAt(0) + 13 > 65 + 25)
      return String.fromCharCode(char.charCodeAt(0) + 13 - 26);
    else return String.fromCharCode(char.charCodeAt(0) + 13);
  } else {
    return char;
  }
}
