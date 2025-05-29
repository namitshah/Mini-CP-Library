#include<bits/stdc++.h>
using namespace std;

//Initializes the DSU Sets.
void generateDSU(int n, int* dsu_set, int* tree_size)
{
  for(int i = 0; i < n; i++)
  {dsu_set[i] = i; tree_size[i] = 1;}
}

//Uses Path Compression for Optimization.
int findRepresentative(int v, int* dsu_set, int* tree_size)
{
  if(dsu_set[v] == v)
  return v;
  return dsu_set[v] = findRepresentative(dsu_set[v], dsu_set, tree_size);
}

//Uses Union by Rank (Tree Size here).
void joinSets(int u, int v, int* dsu_set, int* tree_size)
{
  int src = findRepresentative(u, dsu_set, tree_size);
  int dest = findRepresentative(v, dsu_set, tree_size);

  if(src == dest) return;
  if(tree_size[src] > tree_size[dest])
  {
    src ^= dest;
    dest ^= src;
    src ^= dest;
  }
  dsu_set[src] = dest;
  tree_size[dest] += tree_size[src];
}

int main()
{
  int n; cin >> n;
  int dsu_set[n] = {};
  int tree_size[n] = {};
  generateDSU(n, dsu_set, tree_size);

  int q; cin >> q;
  for(int i = 0; i < q; i++)
  {
    int u, v; cin >> u >> v;
    cout << findRepresentative(u, dsu_set, tree_size) << " "
    << findRepresentative(v, dsu_set, tree_size) << endl;
    joinSets(u, v, dsu_set, tree_size);
  }
  return 0;
}
