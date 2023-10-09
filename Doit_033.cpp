// 우선 순위 큐를 이용하여 작은 것 두 개씩 더하기

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int> > q;  // greater 오름차순

  int number;
  for (int i = 0; i < n; i++) {
    cin >> number;
    q.push(number);
  }

  int data1 = 0, data2 = 0, sum = 0;
  while (q.size() != 1) {
    data1 = q.top();
    q.pop();
    data2 = q.top();
    q.pop();
    sum += data1 + data2;
    q.push(data1 + data2);
  }
  cout << sum << "\n";
}