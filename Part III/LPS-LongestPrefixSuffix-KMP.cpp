#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;

vector<int> lps_of_namit(string &s)
{
  int n = s.length();
  vector<int> out(n);
  int len = 0;
  for(int i = 1; i < n; i++)
  {
    if(s[i] == s[len])
    {out[i] = out[i - 1] + 1; len++;}
    else
    {
      while(len > 0)
      {
        if(s[i] != s[len])
        {len = out[len - 1];}
        else break;
      }
      if(s[i] == s[len])
      out[i] = out[len] + 1, len++;
    }
  }
  return out;
}

int main()
{
  string s; cin >> s;
  auto out = lps_of_namit(s);
  for(int val : out)
  cout << val << " ";
  cout << endl;
  return 0;
}
