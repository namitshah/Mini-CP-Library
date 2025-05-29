#include<bits/stdc++.h>
using namespace std;
//A program to find the lowest common ancestor of two vertices of a tree.
struct SegTree
{
  int left = -1;
  int right = -1;
  pair<int, int> value;
};

//Initialize the tree.
pair<int, int> initializer(int l, int r, vector<pair<int, int>> &arr, vector<SegTree>& sgt, int& current)
{
  SegTree &curr = sgt[current];
  if(r - l == 0)
  {
    curr.value = arr[l];
    return curr.value;
  }
  curr.left = ++current;
  //Replace with the required operation.
  curr.value = initializer(l, (l + r) / 2, arr, sgt, current);
  curr.right = ++current;
  //Replace with the required operation.
  curr.value = min(curr.value, initializer((l + r) / 2 + 1, r, arr, sgt, current));
  return curr.value;
}

//Handle query for a particular range.
pair<int, int> queryHandler(int l, int r, int rl, int rr, vector<SegTree>& sgt, SegTree croot)
{
  if(l == r)
  {return croot.value;}
  //Initialize based on the nature of the operation.
  pair<int, int> output = {1e+9, 0}; int mid = (l + r) / 2;
  if(rl <= mid)
  {
    auto tout = (rl == l && rr >= mid?sgt[croot.left].value:
                  queryHandler(l, mid, rl, min(rr, mid), sgt, sgt[croot.left]));
    //Replace with the required operation.
    output = tout;
  }
  if(rr > mid)
  {
    auto tout = (rl <= mid + 1 && rr == r?sgt[croot.right].value:
                  queryHandler(mid + 1, r, max(mid + 1, rl), rr, sgt, sgt[croot.right]));
    //Replace with the reqired operation.
    output = min(output, tout);
  }
  return output;
}

void dfs(int parent, int index, int depth, vector<vector<int>> &edges, vector<int> &pos, vector<pair<int, int>> &segdata)
{
  segdata.push_back({depth, index});
  pos[index] = segdata.size() - 1;
  for(int edge : edges[index])
  {
    if(edge == parent) continue;
    dfs(index, edge, depth + 1, edges, pos, segdata);
    segdata.push_back({depth, index});
  }
}

class LCA
{
  vector<int> pos;
  vector<pair<int, int>> segdata;
  vector<SegTree> sgt;
public:
  LCA(vector<vector<int>> &edges)
  {
    pos = vector<int>(edges.size(), -1);
    dfs(-1, 0, 1, edges, pos, segdata);
    sgt = vector<SegTree>(segdata.size() * 2);
    int current = 0;
    initializer(0, segdata.size() - 1, segdata, sgt, current);
  }

  pair<int, int> findAncestor(int u, int v)
  {return queryHandler(0, segdata.size() - 1, min(pos[u], pos[v]), max(pos[u], pos[v]), sgt, sgt[0]);}
};

int main()
{
  int n; cin >> n;
  vector<vector<int>> edges(n);
  for(int i = 0; i < n - 1; i++)
  {
    int l, r; cin >> l >> r;
    l--; r--;
    edges[l].push_back(r);
    edges[r].push_back(l);
  }
  LCA obj(edges);
  cout << obj.findAncestor(3, 4).second + 1 << endl;
  return 0;
}
