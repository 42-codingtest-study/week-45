const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim();

solution(input);

function solution(input) {
    const DATA = input.split("-");
    let result = 0;
    const REAL_DATA = DATA.map((v) => v.split("+").map(Number));
    for (let i = 0; i < REAL_DATA.length; i++) {
        REAL_DATA[i] = REAL_DATA[i].reduce((acc, now) => acc + now, 0);
    }
    REAL_DATA.length > 1
        ? (result = REAL_DATA.reduce((acc, now) => acc - now, REAL_DATA[0] * 2))
        : (result = REAL_DATA[0]);

    console.log(result);
}
