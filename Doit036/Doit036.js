const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim();

solution(input);

function solution(input) {
    const DATA = input.split("-"); //일단 - 끼리 자르고
    let result = 0;
    const REAL_DATA = DATA.map((v) => v.split("+").map(Number)); // 그다음에 +끼리 자르는거임
    for (let i = 0; i < REAL_DATA.length; i++) {
        REAL_DATA[i] = REAL_DATA[i].reduce((acc, now) => acc + now, 0);
    } // +들 연산 해
    REAL_DATA.length > 1 //사망연싼자
        ? (result = REAL_DATA.reduce((acc, now) => acc - now, REAL_DATA[0] * 2)) // 이제빼주자
        : (result = REAL_DATA[0]); // 없으면 그냥 해버리는거임

    console.log(result);
}
