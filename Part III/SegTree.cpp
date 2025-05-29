#include<bits/stdc++.h>
using namespace std;

struct SegTree
{
  int left = -1;
  int right = -1;
  int value = 0;
};

//For modifying a node and updating the tree.
int modsegnode(int l, int r, int index, int value, vector<SegTree>& sgt, SegTree &croot)
{
  //Initialize based on the nature of the operation.
  int output = 0, mid = (l + r) / 2;
  if(l == r)
  {croot.value = value; return value;}
  if(index <= mid)
  {
    output = modsegnode(l, mid, index, value, sgt, sgt[croot.left]);
    output = __gcd(output, sgt[croot.right].value);
  }
  else
  {
    output = modsegnode(mid + 1, r, index, value, sgt, sgt[croot.right]);
    output = __gcd(output, sgt[croot.left].value);
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
  if(l == r)
  {return croot.value;}
  //Initialize based on the nature of the operation.
  int output = 0, mid = (l + r) / 2;
  if(rl <= mid)
  {
    int tout = (rl == l && rr >= mid?sgt[croot.left].value:
                  queryHandler(l, mid, rl, min(rr, mid), sgt, sgt[croot.left]));
    //Replace with the required operation.
    output = tout;
  }
  if(rr > mid)
  {
    int tout = (rl <= mid + 1 && rr == r?sgt[croot.right].value:
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
    int index, value; cin >> index >> value;
    modsegnode(0, n - 1, index - 1, value, sgt, sgt[0]);
    cout << queryHandler(0, n - 1, 0, n - 1, sgt, sgt[0]) << endl;
  }
  return 0;
}
//Always be on the lookout for bugs...
