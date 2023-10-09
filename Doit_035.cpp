#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > time(n);

  for (int i = 0; i < n; i++) {  // 종료 시간 정렬을 sort로 하려면 종료 시간
                                 // 먼저 받기 second 시작 시간
    // first 종료 시간
    cin >> time[i].second >> time[i].first;
  }
  sort(time.begin(), time.end());
  int count = 0, end = -1;

  for (int i = 0; i < n; i++) {
    if (time[i].second >=
        end) {  // 시작 시간이 이전 종료 시간보다 크거나 같으면
      end = time[i].first;  // 종료 시간을 현재 종료 시간으로 바꾸고
      count++;              // 회의 수 증가
    }
  }
  cout << count << "\n";
}