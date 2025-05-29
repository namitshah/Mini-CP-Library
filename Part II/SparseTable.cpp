#include<bits/stdc++.h>
using namespace std;

//Using 2^20 as the upper limit (more than 1e+6)
//Using int as type and min as operation (RMQ).
//Generates a Sparse Table, a great alternative to Segment Tree.
//It can't handle updates however.
int powers[21] = {1};
int MAX = 1e+9 + 1;
int generateValue(int (*dp)[21], int n, bool (*flags)[21], int *arr, int pos, int power)
{
  if(flags[pos][power])
  {return dp[pos][power];}
  if(pos + powers[power] > n) return 0;
  flags[pos][power] = true;

  if(power == 0)
  {dp[pos][power] = arr[pos];}
  else
  {dp[pos][power] = min(generateValue(dp, n, flags, arr, pos, power - 1),
    generateValue(dp, n, flags, arr, pos + powers[power - 1], power - 1));}

  //Replace the above operation with the required one (any idempotent op.).
  return dp[pos][power];
}

void sparseTableGenerator(int (*dp)[21], int n, bool (*flags)[21], int *arr)
{
  for(int i = 1; i < 21; i++)
  {powers[i] = powers[i - 1] * 2;}
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < 21; j++)
    {generateValue(dp, n, flags, arr, i, j);}
  }
}

int queryHandler(int (*dp)[21], int n, int l, int r)
{
  //Initialize it in an appropriate way.
  int output = MAX;
  int length = r - l + 1;
  int curr = r;
  int power = 0;
  while(length)
  {
    if(length % 2)
    {output = min(output, dp[(curr -= powers[power]) + 1][power]);}
    length /= 2;
    power++;
  }
  return output;
}

int main()
{
  int n; cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++)
  {cin >> arr[i];}

  int dp[n][21];
  bool flags[n][21] = {};
  sparseTableGenerator(dp, n, flags, arr);

  int q; cin >> q;
  for(int i = 0; i < q; i++)
  {
    //l and r start from 1 here (and are inclusive).
    int l, r; cin >> l >> r;
    cout << queryHandler(dp, n, l - 1, r - 1) << endl;
  }
  return 0;
}
