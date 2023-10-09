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

// N: 카드 묶음의 수, tmp: 입력값 임시 저장, ans: 최종 비용, v: 두 묶음의 합
int N, tmp, ans, v;
priority_queue<int, vector<int>, greater<int> >
    pq;  // 최소 힙을 사용한 우선순위 큐

int main() {
  fast;
  cin >> N;
  // 카드 묶음의 크기 입력받고, 우선순위 큐에 추가
  while (N--) cin >> tmp, pq.push(tmp);

  // 우선순위 큐에 카드 묶음이 하나만 남을 때까지 반복
  // 가장 작은 묶음 가져오기 + 다음으로 작은 묶음 가져와서 합하기
  // 현재 합친 비용을 전체 비용에 더하고 다시 우선순위 큐에 추가
  while (pq.size() != 1)
    v = pq.top(), pq.pop(), v += pq.top(), pq.pop(), ans += v, pq.push(v);

  cout << ans;  // 최소 비용 출력
}
