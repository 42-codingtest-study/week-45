#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 회의를 가장 많이 할 수 있게 하기
//~~할때 필요한  ~~최소갯수 로 말 못만들겠는데 그냥 그리디로 하깅
// 회의 끝나는 시간 기준으로 정렬한다.

vector<pair<int, int>> times;

int main()
{
  int n, tmp1, tmp2;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> tmp1 >> tmp2;
    times.push_back(make_pair(tmp2, tmp1));
  }
  sort(times.begin(), times.end());

  int idx = 0;
  int cnt = 0;
  // idx 값을 회의 시작하는 시간 이랑 비교해서 idx 가 더 작으면 idx 를 새 회의의 끝나는시간으로 바꾼다. (바뀔때가 새 회의 시작되는거)
  for (int i = 0; i < n; i++)
  {
    if (idx > times[i].second)
      continue;
    cnt++;
    idx = times[i].first;
  }
  cout << cnt << "\n";
  return 0;
}