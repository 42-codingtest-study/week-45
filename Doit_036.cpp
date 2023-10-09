#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string input, char check) {  // 문자열을 check 기준으로
                                                  // 나눠서 vector에 넣어 반환
  vector<string> res;          // 반환할 vector
  string splitInput;           // 문자열을 임시로 저장할 변수
  stringstream stream(input);  // input을 stream에 넣음

  while (getline(stream, splitInput, check))
    res.push_back(splitInput);  // check 기준으로 나눠서 vector에 넣음

  return res;
}

int stringSum(string input) {  // 문자열을 숫자로 바꿔서 합을 반환
  int sum = 0;
  vector<string> sumString = split(input, '+');

  for (int i = 0; i < sumString.size(); i++) {
    sum += stoi(sumString[i]);
  }
  return sum;
}
int main() {
  string input;
  cin >> input;

  vector<string> str = split(input, '-');
  int result = 0;
  for (int i = 0; i < str.size(); i++) {
    int tmp = stringSum(str[i]);
    if (i == 0)  // 첫 번째는 더해줘야 함
      result += tmp;
    else  // 2번째부터는 빼줘야 함
      result -= tmp;
  }
  cout << result << "\n";
}