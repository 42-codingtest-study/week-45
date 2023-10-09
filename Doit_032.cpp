#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

// 가치를 나눌 수 있는 금액 중 가장 큰걸 이용하는게 가장 좋음 
// k원를 만드는 데 필요한 동전의 개수의 최솟값을 구하세요 -> 그리디

//생각할만한 예외? 1. 정수 범위를 넘어가노? -> k가 정수 범위 이내라 ㄱㅊ
//2. 동전으로 못만드는경우? -> 0개 나오노

int main()
{
  int n, k;
  int cnt = 0;
  int arr[10];

  cin>>n>>k;
  for (int i = 0; i < n; i++)
    cin>>arr[i];
  
  for (int i = n-1; i >= 0; i--)
  {
    if (arr[i] <= k)
    {
      while (k >= arr[i])
      {
        int left = k % arr[i];
        cnt += k/arr[i];
        k = left;
      }
    }
  }
  cout<<cnt<<"\n";

  return 0;
}