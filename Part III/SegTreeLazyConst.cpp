#include<bits/stdc++.h>
using namespace std;
//A segment tree with lazy propagation capability.
//Can set all variables in a range to a constant value in O(LogN).
//This one computes the GCD. For other operations, lazyval might need to be
//multiplied by the range that it covers.
//Written by Namit Shah (Namit/Eclecticity).
struct SegTree
{
  int left = -1;
  int right = -1;
  int value = 0;
  //For Lazy Propagation.
  bool isLazy = false;
  int lazyval = 0;
};

//For modifying a node and updating the tree.
int modsegnodes(int l, int r, int rl, int rr, int value, vector<SegTree>& sgt, SegTree &croot)
{
  //Initialize based on the nature of the operation.
  //Also change the complicated else parts as this was fashioned from queryHandler().
  int output = 0, mid = (l + r) / 2;
  if(l == r)
  {croot.value = value; return value;}
  if(croot.isLazy)
  {
    sgt[croot.left].isLazy = true, sgt[croot.left].lazyval = croot.lazyval;
    sgt[croot.right].isLazy = true, sgt[croot.right].lazyval = croot.lazyval;
    croot.isLazy = false;
  }
  if(rl <= mid)
  {
    int tout = (rl == l && rr >= mid?(sgt[croot.left].isLazy = true, sgt[croot.left].lazyval = value):
                  modsegnodes(l, mid, rl, min(rr, mid), value, sgt, sgt[croot.left]));
    //Replace with the required operation.
    output = tout;
  }
  else
  {
    if(sgt[croot.left].isLazy) output = sgt[croot.left].lazyval;
    else output = sgt[croot.left].value;
  }
  if(rr > mid)
  {
    int tout = (rl <= mid + 1 && rr == r?(sgt[croot.right].isLazy = true, sgt[croot.right].lazyval = value):
                  modsegnodes(mid + 1, r, max(mid + 1, rl), rr, value, sgt, sgt[croot.right]));
    //Replace with the reqired operation.
    output = __gcd(output, tout);
  }
  else
  {
    if(sgt[croot.right].isLazy) output = __gcd(output, sgt[croot.right].lazyval);
    else output = __gcd(output, sgt[croot.right].value);
  }
  croot.value = output;
  return output;
}

//Initialize the tree.
int initializer(int l, int r, int* arr, vector<SegTree>& sgt, int& current)
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
  curr.value = __gcd(curr.value, initializer((l + r) / 2 + 1, r, arr, sgt, current));
  return curr.value;
}

//Handle query for a particular range.
int queryHandler(int l, int r, int rl, int rr, vector<SegTree>& sgt, SegTree croot)
{
  if(croot.isLazy) return croot.lazyval;
  if(l == r)
  {return croot.value;}
  //Initialize based on the nature of the operation.
  int output = 0, mid = (l + r) / 2;
  if(rl <= mid)
  {
    int tout = (rl == l && rr >= mid?(sgt[croot.left].isLazy?sgt[croot.left].lazyval:sgt[croot.left].value):
                  queryHandler(l, mid, rl, min(rr, mid), sgt, sgt[croot.left]));
    //Replace with the required operation.
    output = tout;
  }
  if(rr > mid)
  {
    int tout = (rl <= mid + 1 && rr == r?(sgt[croot.right].isLazy?sgt[croot.right].lazyval:sgt[croot.right].value):
                  queryHandler(mid + 1, r, max(mid + 1, rl), rr, sgt, sgt[croot.right]));
    //Replace with the reqired operation.
    output = __gcd(output, tout);
  }
  return output;
}

//A basic demo of the functions.
int main()
{
  int n; cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++)
  {cin >> arr[i];}
  vector<SegTree> sgt(2 * n);
  int current = 0;
  initializer(0, n - 1, arr, sgt, current);
  //The second set of l and r specify the required range.
  int q; cin >> q;
  for(int i = 0; i < q; i++)
  {
    int iL, iR, value; cin >> iL >> iR >> value;
    modsegnodes(0, n - 1, iL - 1, iR - 1, value, sgt, sgt[0]);
    for(int i = 0; i < n; i++)
    {
      cout << queryHandler(0, n - 1, i, i, sgt, sgt[0]) << " ";
    }
    cout << ":" << queryHandler(0, n - 1, 0, n - 1, sgt, sgt[0]) <<endl;
  }
  return 0;
}
//Always be on the lookout for bugs...
