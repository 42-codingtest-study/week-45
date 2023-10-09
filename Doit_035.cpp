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

int N, s, e;  // N: 회의의 수, s: 시작 시간, e: 끝나는 시간
vector<pair<int, int> > times;  // 회의 일정을 저장할 벡터

int main() {
  fast;
  cin >> N;
  // 각 회의의 시작 시간과 끝나는 시간 입력 받기
  // 끝나는 시간을 첫 번째로 하여 저장 (끝나는 시간 순으로 정렬하기 위해)
  while (N--) cin >> s >> e, times.push_back(make_pair(e, s));
  sort(times.begin(), times.end());  // 끝나는 시간을 기준으로 정렬

  // 첫 번째 회의 선택
  s = times[0].second, e = times[0].first, N = 1;
  for (int i = 1; i < times.size(); i++)
    // 이전 회의가 끝나고 다음 회의가 시작하는 경우, 회의 개수 증가
    if (times[i].second >= e) s = times[i].second, e = times[i].first, N += 1;

  cout << N;  // 가능한 최대 회의 개수 출력
}
