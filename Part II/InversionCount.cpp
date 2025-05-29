#include<bits/stdc++.h>
using namespace std;

long long inversionCountFinder(vector<int> &arr, int start, int end)
{
  if(start == end) return 0;
  int n = arr.size(), mid = (start + end) / 2;
  long long out = 0;
  out += inversionCountFinder(arr, start, mid);
  out += inversionCountFinder(arr, mid + 1, end);
  int i = start, j = mid + 1;
  vector<int> output;
  while(i <= mid || j <= end)
  {
    if(i > mid)
    {output.push_back(arr[j++]);}
    else if(j > end)
    {output.push_back(arr[i++]);}
    else
    {
      if(arr[i] < arr[j])
      {output.push_back(arr[i++]);}
      else
      {
        output.push_back(arr[j++]);
        out += mid - i + 1;
      }
    }
  }
  for(int i = start; i <= end; i++)
  {arr[i] = output[i - start];}
  return out;
}

int main()
{
  int n; cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++)
  {cin >> arr[i];}
  cout << inversionCountFinder(arr, 0, n - 1) << endl;
  return 0;
}
