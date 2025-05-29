//Some Algos:

//A function for finding the square root with
//100% chances of working, lol.
__int128 sqr_root(__int128 x)
{
  __int128 sroot = sqrt((long double)x);
  while(sroot * sroot <= x)
  sroot++;
  while(sroot * sroot > x)
  sroot--;
  return sroot;
}

//Finding the closest (by distance) greater/equal element to the right.
//Done using a stack with a complexity of O(N).
stck.push({arr[0], 0});
for(int i = 1; i < n; i++)
{
  while(stck.size() && arr[i] >= stck.top().first)
  {nxmx[stck.top().second] = i; stck.pop();}
  stck.push({arr[i], i});
}
//nxmx is an array pointing to the next maxes.

//Execution Time Calculator:
using namespace std::chrono;
auto start = high_resolution_clock::now();
//Update value of start at the 'start' point.
int executionTime()
{
  return duration_cast<milliseconds>
  (high_resolution_clock::now() - start).count();
}

//Order Statistics Tree for maintaining the indices of elements.
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
//Replace pair<int, int> with the datatype to be used...
//Otherwise, works just like a set (supports all ops.).
typedef tree<pair<int, int>, null_type,
  less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
  OrdStat;

int func()
{
  OrdStat ord_stat;
  ord_stat.insert(pair<int, int>(1, 1));
  ord_stat.insert(pair<int, int>(1, 2));
  cout << ord_stat.order_of_key(pair<int, int>(1, 1)) << endl;
  cout << (*ord_stat.find_by_order(1)).second << endl;
  ord_stat.erase(*ord_stat.find_by_order(0));
  cout << "reached here!" << endl;
  auto itr = ord_stat.begin();
  cout << ord_stat.size() << endl;
  cout << (*itr).second << endl;
  return 0;
}

//Kadane's Algorithm:
//(Finds the Sub-Array with the highest sum)
long long first = 0, max1 = 0;
for(int i = 0; (i+1) < n; i+=2)
{
  long long current = -arr[i] + arr[i + 1];
  first += current;
  if(first > max1)
  {max1 = first;}
  if(first < 0)
  {first = 0;}
}


//Fermat's Little Theorem: A^(m - 2)
//Only computes the number here...
long long modder;
int fermats_little_theorem(long long number, long long power)
{
  if(power == 0)
  {return 1;}
  long long out = fermat(number, power / 2);
  out = out * out % modder;
  if(power % 2 == 1)
  {out = out * number % modder;}
  return out;
}

//Find the unique prime factors of a number and store them in a vector.
//Another vector holds the number of instances of each unique prime factor.
vector<int> storage, quantity;
void factorizeMe(int current)
{
  for(int j = 2; j <= sqrt(current); j++)
  {
    int instances = 0;
    if(current % j == 0)
    {storage.push_back(j);}
    while(current % j == 0)
    {current /= j; instances++;}
    if(instances > 0)
    {quantity.push_back(instances);}
  }
  if(current != 1)
  {storage.push_back(current); quantity.push_back(1);}
}

//Sieve of Eratosthenes:
vector<int> primes;
void acolyte()
{
  bool flags[(int)1e+5 + 1] = {};
  for(long long i = 2; i <= 1e+5; i++)
  {
    if(flags[i]){continue;}
    primes.push_back(i);
    for(long long j = i * i; j <= 1e+5; j += i)
    {flags[j] = true;}
  }
  cout << primes.size() << endl; //9592
}
