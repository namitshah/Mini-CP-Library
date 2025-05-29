//Solution to CF514C.
//Rolling hash is used here for narrowing
//down the scope of comparison.
//Direct comparison is used for confirmation.
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
int modder = 1e+9 + 7;
int power(int a, int b)
{
  if(b == 0) return 1;
  long long out = power(a, b / 2);
  out *= out; out %= modder;
  if(b % 2) out *= a;
  return out % modder;
}

int hasher(string &s)
{
  long long out = 0;
  for(int i = 0; i < s.length(); i++)
  out += (s[i] - 'a') * (long long)power(29791, i), out %= modder;
  return out;
}

void processor()
{
  int n, m; cin >> n >> m;
  set<int> candies;
  map<int, set<string>> data;
  for(int i = 0; i < n; i++)
  {
    string s; cin >> s;
    int hash = hasher(s);
    candies.insert(hash);
    data[hash].insert(s);
  }
  for(int i = 0; i < m; i++)
  {
    string m; cin >> m;
    bool flag = false;
    int hash = hasher(m);
    for(int i = 0; i < m.length(); i++)
    {
      char orig = m[i];
      for(int j = 'a'; j < 'd'; j++)
      {
        if(orig == j) continue;
        m[i] = j;
        int nhash = (hash + (m[i] - orig) * (long long)power(29791, i))
        % modder;
        if(nhash < 0) nhash += modder;
        if(candies.find(nhash) != candies.end())
        {
          for(string s : data[nhash])
          if(s == m) flag = true;
        }
      }
      m[i] = orig;
    }
    cout << (flag?"YES":"NO") << "\n";
  }
  return;
}

/*WhAt ArE dAyS fOr?|----|DaYs ArE wHeRe We LiVe */
/*ThEy CoMe, ThEy WaKe Us|---|TiMe AnD tImE oVeR.*/
/*ThEy--*/int main()
/*aRe tO*/{
/*bE HaP*/  ios_base::sync_with_stdio(false);
/*pY iN.*/  cin.tie(NULL);
/*wHeRe */  int count, counter = 0;
/*cAn wE*/  count = 1;
/*lIvE b*/  while(counter++ < count)
/*Ut dAy*/  {processor();}
/*S. aH,*/  return 0;
/*sOlViN*/}
/*g tHaT qUeStIoN bRiNgS tHe PrIeSt AnD tHe DoCt */
/*Or In ThEiR lOnG cOatS RuNnInG oVeR tHe FiElDs.*/
