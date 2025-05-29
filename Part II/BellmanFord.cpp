/*
Bellman Ford example (max path here along with positive cycle detection).
CSES-Graphs-High Score Solution.
Using -1e+16 as -INF.
LIMIT should be >= m (Though sometimes *2 might be necessary).
Think about this and only then set it.
Can be arbitrary.
*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
void processor()
{
  int n, m; cin >> n >> m;
  vector<long long> dists(n, -1e+16L);
  dists[0] = 0;
  vector<pair<pair<int, int>, int>> edges;
  const int LIMIT = m * 3;
  int lastUp[n] = {};
  for(int i = 0; i < m; i++)
  {
    int a, b, c; cin >> a >> b >> c;
    a--, b--;
    edges.push_back({{a, b}, c});
  }
  int count = 0;
  bool change = true;
  while(change)
  {
    change = false;
    for(auto edge : edges)
    {
      auto data = edge.first;
      int val = edge.second;
      if(dists[data.first] != -1e+16 &&
      dists[data.first] + val > dists[data.second])
      {
        change = true;
        dists[data.second] = dists[data.first] + val;
        lastUp[data.second] = count + 1;
      }
      lastUp[data.second] = max(lastUp[data.first],
        lastUp[data.second]);
    }
    count++;
    if(count > LIMIT) change = false;
  }
  count = 0;
  change = true;
  if(lastUp[n - 1] > m)
  cout << -1 << "\n";
  else cout << dists[n - 1] << "\n";
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
