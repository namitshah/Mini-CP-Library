#include<bits/stdc++.h>
using namespace std;

//phi(n) = number of integers from 1 to n (inclusive) that
//are coprime with n.
//Eg. Usage: https://codeforces.com/contest/1717/problem/E
long long tot_func(long long n)
{
    long long out = n, sqr = sqrt(n);
    for (int i = 2; i <= sqr; i++)
    {
      if(n % i) continue;
      while(n % i == 0)
        n /= i;
      out -= out / i;
    }
    if (n > 1)
      out -= out / n;
    return out;
}
