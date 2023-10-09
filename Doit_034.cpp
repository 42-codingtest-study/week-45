#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;

  priority_queue<int> plus;
  priority_queue<int, vector<int>, greater<int> > minus;
  int one_count = 0, zero_count = 0;
  int number;

  for (int i = 0; i < n; i++) {
    cin >> number;
    if (number == 0)
      zero_count++;
    else if (number == 1)
      one_count++;
    else if (number > 1)
      plus.push(number);
    else
      minus.push(number);
  }

  int sum = 0, data1 = 0, data2 = 0;
  while (plus.size() > 1) {
    data1 = plus.top();
    // cout << data1 << "\n";
    plus.pop();
    data2 = plus.top();
    plus.pop();
    sum += data1 * data2;
  }
  if (!plus.empty()) {
    sum += plus.top();
    plus.pop();
  }
  while (minus.size() > 1) {
    data1 = minus.top();
    minus.pop();
    data2 = minus.top();
    minus.pop();
    sum += data1 * data2;
  }
  if (!minus.empty()) {
    if (zero_count == 0) {
      sum += minus.top();
      minus.pop();
    }
  }
  sum += one_count;
  cout << sum << "\n";
}
