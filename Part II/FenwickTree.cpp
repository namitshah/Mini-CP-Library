#include<bits/stdc++.h>
using namespace std;
//A Fenwick Tree implementation. Can be tuned for any RMQ (only prefixes).
//Finds the sum here.
//The tree is 1-indexed.
//BIT should only be used with operations that have inverses;
//Eg: Addition does but GCD doesn't.
//Fenwick (Binary Indexed) is simpler and faster than seg. but less versatile.
void fenwickIU(int val, int index, vector<long long> &arr)
{
  if(!index || index > arr.size() || index < 0) return;
  int lsb = index & (-index);
  arr[index - 1] += val;
  fenwickIU(val, index + lsb, arr);
}

long long fenwickGet(int index, vector<long long> &arr)
{
  if(!index) return 0;
  int lsb = index & (-index);
  return arr[index - 1] + fenwickGet(index - lsb, arr);
}

int main()
{
  int n; cin >> n;
  vector<long long> arr(n);
  for(int i = 0; i < n; i++)
  {
    int current; cin >> current;
    fenwickIU(current, i + 1, arr);
  }
  for(int i = 0; i < n; i++)
  {cout << fenwickGet(i + 1, arr) << endl;}
  //Updates are done in the form of constant 'shifts/inversions' (arr[i] + val).
  fenwickIU(-3, 3, arr);
  cout << "Updated: " << fenwickGet(arr.size(), arr);
  return 0;
}
