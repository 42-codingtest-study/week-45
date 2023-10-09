#include <iostream>
#include <vector>
#include <string>

using namespace std;

//걍 - 랑 - 사이에 있는 값 다 더해서 뺀다.
//split 구현한거 기억해두기ㅋㅋ
vector<string> split(string str, char delimiter)
{
	vector<string> vs;
	string temp;

	for (int i = 0; !(str[i] == 13 || str[i] == '\n' || str[i] == 0); i++)
	{
		if (str[i] == delimiter)
		{
			vs.push_back(temp);
			temp.clear();
			continue;
		}
		temp.push_back(str[i]);
	}
	vs.push_back(temp); 

	return vs;
}
int main()
{
  string input;
  cin>>input;

  vector<string> seperated_minus = split(input, '-');
  vector<int> seperated_plus;
  for (int i = 0; i < seperated_minus.size(); i++)
  {
    vector<string> seperated = split(seperated_minus[i], '+');
    int sum = 0;
    for (int j = 0; j < seperated.size(); j++)
      sum += stoi(seperated[j]);
    seperated_plus.push_back(sum);
  }
  
  int ans = seperated_plus[0];
  for (int i = 1; i < seperated_plus.size(); i++)
    ans -= seperated_plus[i];
  cout<<ans<<"\n";
  return 0;
}