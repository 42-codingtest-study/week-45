//문제: Doit034
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);

// 4개의 경우의 수를 나눠야 됨
// n < 0 => 음수는 절댓값이 가장 큰것부터 두개 씩 묶어서 더해야됨
// n == 0 => 음수가 홀수개면 0을 곱해서 없애버릴 용도, 0이 여러개면 하나 빼고는 무시해도 됨 사실 음수가 짝수개면 0그냥 무시 홀수개면 0하나 쓰기
// n == 1 1은 그냥 더해주는게 최고
// n > 1 큰값부터 두개씩 곱해서 더해야함
function solution(input) {
    const N = +input.shift();
    const ARR = input.map(Number).sort((a, b) => a - b);
    let answer = 0;
    //N은 50보다 작은 자연수라 그냥 sort해도 되겠다
    const MINUS = [];
    const YOUNG = [];
    const IL = [];
    const PLUS = [];
    ARR.forEach((e) => {
        if (e < 0) MINUS.push(e);
        else if (e === 0) YOUNG.push(e);
        else if (e === 1) IL.push(e);
        else PLUS.push(e);
    });
    if (MINUS.length % 2 === 0) {
        for (let i = 0; i < MINUS.length; i += 2) {
            answer += MINUS[i] * MINUS[i + 1];
        }
        // console.log(answer);
    } else {
        if (!YOUNG.length) answer += MINUS[MINUS.length - 1];
        // console.log(answer);

        for (let i = 0; i < MINUS.length - 1; i += 2) {
            answer += MINUS[i] * MINUS[i + 1];
        }
        // console.log(answer);
    }
    answer += IL.length;
    // console.log(answer);
    if (PLUS.length % 2 !== 0) {
        answer += PLUS.shift();
    }
    // console.log(answer);
    for (let i = 0; i < PLUS.length; i += 2) {
        answer += PLUS[i] * PLUS[i + 1];
    }
    console.log(answer);
}
