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
  queue<int> to_be_compressed;
  while(dsu_set[v] != v)
  {
    to_be_compressed.push(v);
    v = dsu_set[v];
  }
  while(to_be_compressed.size())
  {
    dsu_set[to_be_compressed.front()] = v;
    to_be_compressed.pop();
  }
  return v;
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

//Run the Kruskal Algorithm. O(N*logN).
set<tuple<int, int, int>> kruskal_of_namit(set<tuple<int, int, int>> edges, int n,
  int* dsu_set, int* tree_size)
{
  set<tuple<int, int, int>> output;
  for(auto edge : edges)
  {
    if(findRepresentative(get<1>(edge), dsu_set, tree_size) == findRepresentative(get<2>(edge),
    dsu_set, tree_size));
    else
    {
      joinSets(get<1>(edge), get<2>(edge), dsu_set, tree_size);
      output.insert(edge);
    }
  }
  return output;
}

int main()
{
  int n, e; cin >> n >> e;
  int dsu_set[n] = {};
  int tree_size[n] = {};
  generateDSU(n, dsu_set, tree_size);

  set<tuple<int, int, int>> edges;
  for(int i = 0; i < e; i++)
  {
    int u, v, weight;
    cin >> u >> v >> weight;
    u--; v--;
    edges.insert(make_tuple(weight, u, v));
  }
  edges = kruskal_of_namit(edges, n, dsu_set, tree_size);
  cout << "The Formed MST is:" << endl;
  long long output = 0;
  for(auto edge : edges)
  {
    cout << get<1>(edge) + 1 << " " << get<2>(edge) + 1 << " " << get<0>(edge) << endl;
    output += get<0>(edge);
  }
  cout << "Total Size: " << output << endl;
  return 0;
}
