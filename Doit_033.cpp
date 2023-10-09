#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
// 고려하기 시간제한 그리디면 ㄱㅊ고, 메모리도 배열크기 10만에 128메가면 충분함.

// 하나의 숫자묶음 만드는데 필요한 비교횟수의 최솟값 -> 그리디
// 우선순위큐에 담으면 작은 숫자대로 담길것이고,
//  작은거 두개 부터 합치기 시작하면 된다.
//  pq 디폴트가 내림차순이라 오름차순으로 바꿨어요
// 예외 : 메모리, 시간 다 괜찮음. 100000이 다 1000 일 때도 숫자범위 안넘어감.

priority_queue<int, vector<int>, greater<int>> pq;
int n;
int arr[100002];

int main()
{
  int tmp;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> tmp;
    pq.push(tmp);
  }
  int ans = 0;

  while (pq.size() > 1)
  {
    int one = pq.top();
    pq.pop();
    int two = pq.top();
    pq.pop();

    ans += one;
    ans += two;
    pq.push(one + two);
  }
  cout << ans << "\n";
  return 0;
}