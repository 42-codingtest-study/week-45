//문제: Doit032
//0. 문제 이해 :  K원을 만드는데 필요한 동전의 개수
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인: 언제나 그렇듯이 문제에서 힌트를 얻어보자!
// ~~를 만드는데 필용한 ~~ 개의 최소(최대) 값을 구하여라 => 그리디의 기본 루트
// 그러면 그리디를 적용해보자 !
// 그리디 3단계
// 1. 현재에서 최선의 해를 찾는다
// 2. 현재의 해가 전체의 제약 조건에 맞는지 확인한다.
// 3. 현재까지 선택한 해 집합이 전체 문제를 해결할 수 있는지 확인한다.
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    let [n, k] = input.shift().split(" ").map(Number); // 10 4200
    const COIN = input.map(Number); //[1,5,10, 50, 100 ..]
    let answer = 0;
    for (let i = n - 1; i >= 0; i--) {
        //COIN 배열을 내림차순으로 내려오면서 k값보다 작거나 같으면 k에서 해당 코인만큼 빼주고 인덱스를 그대로 돌려놓는다!
        if (k >= COIN[i]) {
            k -= COIN[i];
            i++;
            answer++; // 뻬줄때마다 answer를 증가시켜주면 몇번하는지 알 수 있겠지!
        }
    }
    console.log(answer);
}
