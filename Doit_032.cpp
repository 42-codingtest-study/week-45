#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> vec(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }

  int count = 0;
  for (int i = n - 1; i >= 0; i--)  // 뒤에서부터 확인
  {
    if (vec[i] <= k) {
      count += (k / vec[i]);
      k = k % vec[i];
    }
  }
  cout << count << "\n";
}