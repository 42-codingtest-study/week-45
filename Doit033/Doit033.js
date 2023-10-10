//문제: Doit033
//0. 문제 이해 :
//1. 시간 복잡도 확인:
//2. 적용 알고리즘 확인:
//3. 맞는 자료구조 확인:
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

solution(input);
function solution(input) {
    const N = +input[0]; //3

    const heap = []; //원래는 그냥 더했는데 메모리 초과나서 넣을때마다 자동 정렬될 수 있도록 heap을 만들었움다
    let size = 0;

    const swap = (idx1, idx2) => {
        let tmp = heap[idx1];
        heap[idx1] = heap[idx2];
        heap[idx2] = tmp;
    };

    const push = (x) => {
        if (size === 0) heap[1] = x;
        else {
            let pos = size + 1;
            heap[pos] = x;
            while (heap[pos] < heap[Math.floor(pos / 2)] && pos !== 1) {
                swap(pos, Math.floor(pos / 2));
                pos = Math.floor(pos / 2);
            }
        }
        size++;
    };

    const top = () => {
        if (size === 0) return 0;
        return heap[1];
    };

    const pop = () => {
        if (size === 0) return;
        let pos = 1;
        heap[pos] = heap[size];
        heap.pop();
        while (
            (heap[pos * 2] && heap[pos] > heap[pos * 2]) ||
            (heap[pos * 2 + 1] && heap[pos] > heap[pos * 2 + 1])
        ) {
            if (heap[pos * 2] > heap[pos * 2 + 1]) {
                swap(pos, pos * 2 + 1);
                pos = pos * 2 + 1;
            } else {
                swap(pos, pos * 2);
                pos = pos * 2;
            }
        }
        size--;
    };

    for (let i = 1; i <= N; i++) {
        push(+input[i]);
    }

    let answer = 0;
    //매번 제일 작은거 두개 빠고 그거 더해서 넣는데 그게 정렬되어야됨 => 매번 최선의 해가 최솟값 2개 더하는 거임
    while (size > 1) {
        const first = top();
        pop();
        const second = top();
        pop();
        let sum = first + second;
        answer += sum;
        push(sum); //heap만들어서 알아서 정렬된곳으로 들어감
    }

    console.log(answer);
}
