#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> edges;
int paths[200001][2] = {};
int diametrics[2] = {}, last;
bool flag = false;

void acolyte(int i, int depth, int par)
{
  if(depth > last)
  {
    if(flag) diametrics[1] = i;
    else diametrics[0] = i;
    last = depth;
  }
  for(int edge : edges[i])
  if(edge != par)
  acolyte(edge, depth + 1, i);
}

void processor()
{
  int n; cin >> n;
  edges = vector<vector<int>>(n + 1);
  for(int i = 0; i < n - 1; i++)
  {
    int u, v; cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  //start from random node to get to the first
  //diametric node.
  last = -1;
  acolyte(1, 0, 0);
  last = -1;
  flag = true;
  acolyte(diametrics[0], 0, 0);
  for(int val : diametrics)
  cout << val << "\n";
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
