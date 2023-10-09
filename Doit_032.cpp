#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

// N: 동전 종류의 수, K: 목표 금액, ans: 필요한 동전의 최소 개수
// coins: 동전의 가치를 저장할 배열
int N, K, ans, coins[10];

int main() {
  fast;
  cin >> N >> K;  // 동전 종류의 수와 목표 금액 입력받기
  for (int i = 0; i < N; i++) cin >> coins[i];  // 각 동전의 가치 입력받기

  // 가장 큰 가치의 동전부터 차례로 사용하여 목표 금액을 만들기
  // 해당 동전으로 만들 수 있는 최대 개수 더하기 + 남은 금액 갱신
  for (int i = N - 1; i >= 0; i--) ans += K / coins[i], K %= coins[i];
  cout << ans;
}
