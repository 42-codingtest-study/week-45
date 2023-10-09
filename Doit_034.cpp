#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  // 그냥 음수 벡터, 양수 벡터 각각만드록,
  // 음수 정렬한 후 홀수면 가장 작은 음수만 남기고 나머지는 다 곱해서 양수로 바꿔버리기
  //  양수도 정렬해서 큰수 들끼리 곱하기. (홀수, 짝수 구분, 홀수일 때는 가장 작은 양수랑 가장 작은 음수 두개를 곱할때랑 더할때중에 더 작은 값 고르기)
  int n, tmp;
  long long answer = 0;
  vector<int> plus;
  vector<int> minus;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> tmp;
    if (tmp <= 0)
      minus.push_back(tmp);
    else
      plus.push_back(tmp);
  }
  sort(plus.begin(), plus.end());
  sort(minus.begin(), minus.end(), greater<>());

  if (plus.size() % 2 == 0) // 짝수이면 그냥 다 곱하기?
  {
    // cout<<"양수 짝수개\n";
    for (int i = 0; i < plus.size(); i++)
    {
      if (plus[i] == 1 && plus[i + 1] >= 1)
        answer += (plus[i] + plus[i + 1]);
      else
        answer = answer + plus[i] * plus[i + 1];
      i++;
    }
  }
  else
  {
    //  cout<<"양수 홀수개\n";
    answer += plus[0];
    for (int i = 1; i < plus.size(); i++)
    {
      if (plus[i] == 1 && plus[i + 1] >= 1)
        answer += (plus[i] + plus[i + 1]);
      else
        answer = answer + plus[i] * plus[i + 1];
      i++;
    }
  }
  if (minus.size() % 2 == 0)
  {
    //    cout<<"음수 짝수개\n";
    for (int i = 0; i < minus.size(); i++)
    {
      answer = answer + minus[i] * minus[i + 1];
      i++;
    }
  }
  else
  {
    //  cout<<"양수 홀수개\n";
    answer += minus[0];
    for (int i = 1; i < minus.size(); i++)
    {
      answer = answer + minus[i] * minus[i + 1];
      i++;
    }
  }
  cout << answer << '\n';

  return 0;
}
