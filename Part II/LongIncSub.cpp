#include<bits/stdc++.h>
using namespace std;
//https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
vector<int> LongIncSub(vector<int> &input)
{
  const int INF = 1e+9;
  vector<int> dp(input.size() + 1, INF), output, starts(input.size() + 1, -1), pointers(input.size(), -1);
  dp[0] = -INF;
  for(int i = 0; i < input.size(); i++)
  {
    //Conversion to non-decreasing is easy.
    //Just replace dp[j - 1] < input[i] with dp[j - 1] <= input[i]
    //Also keep an eye on INF.
    int j = upper_bound(dp.begin(), dp.end(), input[i]) - dp.begin();
    if(dp[j - 1] < input[i] && input[i] < dp[j])
    {
      dp[j] = input[i];
      starts[j] = i;
      pointers[i] = starts[j - 1];
    }
  }
  for(int i = input.size(); i > 0; i--)
  {
    if(dp[i] != INF)
    {
      output.push_back(starts[i]);
      int ptr = pointers[starts[i]];
      while(ptr != -1)
      {output.push_back(ptr); ptr = pointers[ptr];}
      break;
    }
  }
  return output;
}

int main()
{
  int n; cin >> n;
  vector<int> input(n);
  for(int i = 0; i < n; i++)
  {cin >> input[i];}
  input = LongIncSub(input);
  //Outputs a zero indexed list of selected positions.
  //The Final Complexity is O(NlogN)
  for(auto val : input)
  {cout << val << " ";}
  cout << endl;
  return 0;
}
