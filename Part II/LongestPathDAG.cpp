#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
long long n, m, k;
int arr[200001];
vector<vector<int>> edges(200001);
//The actual complexity will be O(N), once we get the topo. sorting,
//we can simply process nodes from 1->N (rank-wise).
//dist[a] = max(dists of all its 'parents')
vector<int> topoSort(int targ)
{
  vector<int> out;
  int odg[n + 1] = {};
  queue<int> candies;
  int N = 0;
  vector<vector<int>> inverse(n + 1);
  for(int i = 1; i <= n; i++)
  {
    if(arr[i] > targ) continue;
    N++;
    for(auto edge : edges[i])
    if(arr[edge] <= targ)
    {
      inverse[edge].push_back(i);
      odg[i]++;
    }
    if(!odg[i])
    candies.push(i);
  }
  while(candies.size())
  {
    auto node = candies.front();
    candies.pop();
    out.push_back(node);
    for(auto edge : inverse[node])
    {
      if(arr[edge] > targ) continue;
      odg[edge]--;
      if(!odg[edge])
      candies.push(edge);
    }
  }
  if(out.size() < N)
  {vector<int> temp(1, -1); return temp;}
  reverse(out.begin(), out.end());
  return out;
}

int oacolyte(int i, int targ, int* dp, bool* flags)
{
  if(flags[i]) return dp[i];
  flags[i] = true;
  dp[i] = 1;
  for(int edge : edges[i])
  {
    if(arr[edge] <= targ)
    dp[i] = max(dp[i], oacolyte(edge, targ, dp, flags) + 1);
  }
  return dp[i];
}

int acolyte(int targ)
{
  int dp[n + 1] = {};
  bool flags[n + 1] = {};
  for(int i = 1; i <= n; i++)
  {
    if(arr[i] <= targ)
    oacolyte(i, targ, dp, flags);
  }
  return *max_element(dp, dp + n + 1);
}

void processor()
{
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++)
  cin >> arr[i + 1];
  for(int i = 0; i < m; i++)
  {
    int u, v; cin >> u >> v;
    edges[u].push_back(v);
  }
  int out = -1;
  int start = 0, end = 1e+9;
  while(start <= end)
  {
    int mid = (start + end) / 2;
    auto data = topoSort(mid);
    if((data.size() && data[0] == -1) ||
    acolyte(mid) >= k)
    {
      out = mid;
      end = mid - 1;
    }
    else start = mid + 1;
  }
  cout << out << endl;
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
