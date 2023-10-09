#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

// N: 수열의 길이, ans: 결과값, tmp: 입력값 임시 저장, p1, p2: 묶을 두 수
int N, ans, tmp, p1, p2;
// 최소 힙을 사용한 우선순위 큐
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
  fast;
  cin >> N;
  // 우선순위 큐에 추가
  while (N--) cin >> tmp, pq.push(tmp);

  // 우선순위 큐에서 숫자 두 개씩 묶어 결과 최대화
  while (!pq.empty()) {
    p1 = pq.top(), pq.pop();  // 가장 작은 수 가져오기
    if (pq.empty()) {         // 더 이상 묶을 수 없을 때
      ans += p1;
      break;
    } else if (p1 > 0 && pq.size() % 2 == 0) {
      // 양수일 경우 묶지 않고 바로 결과에 더하기 (pq에 남은요소의 갯수가 2의
      // 배수일 경우에만 한정)
      ans += p1;
      continue;
    }
    p2 = pq.top(), pq.pop();  // 그 다음으로 작은 수 가져오기
    // 조건에 따라 연산 수행
    if (p1 == 0)  // 0인 경우 그냥 무시
      pq.push(p2);
    else if (p2 == 0)  // 0인 경우 그냥 무시
      ;
    else if (p1 == 1)
      ans += 1,
          pq.push(p2);  // 1인 경우 다른 수와 곱하는 것보다 더하는 것이 유리
    else if (p2 == 1)
      ans += p1 + 1;
    else if (p1 < 0 && p2 > 0)
      // 한 수가 음수이고 다른 수가 양수인 경우 곱하지 않고 음수만 결과에 더함
      ans += p1, pq.push(p2);
    else
      ans += p1 * p2;  // 그 외의 경우 두 수를 곱함
  }

  cout << ans;  // 최종 결과 출력
}
