//문제: Doit035
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    // 끝나는 시간 기준 정렬 해야됨 근데 끝나는 시간이 같으면 시작 시간기준으로 정렬해주자!
    const N = input.shift();
    const ARR = input.map((e) => e.split(" ").map(Number));

    ARR.sort((a, b) => {
        if (a[1] === b[1]) {
            return a[0] - b[0];
        } else return a[1] - b[1];
    });
    let end = 0;
    let answer = 0;
    for (let meet of ARR) {
        if (meet[0] >= end) {
            answer++;
            end = meet[1];
        }
    }
    console.log(answer);
    // console.log(ARR);
}
