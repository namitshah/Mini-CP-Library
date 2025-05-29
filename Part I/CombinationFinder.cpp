int combs[5001][5001] = {};
bool fcombs[5001][5001] = {};
int modder = 998244353;

int power(int a, int b)
{
  if(b == 0) return 1;
  long long out = power(a, b / 2);
  out *= out; out %= modder;
  if(b % 2) out *= a;
  return out % modder;
}

int comber(int a, int b)
{
  if(a == 0 || b == 0)
  return 1;
  if(fcombs[a][b])
  return combs[a][b];
  fcombs[a][b] = true;
  long long out = comber(a, b - 1);
  out *= (a - b + 1); out %= modder;
  out *= power(b, modder - 2);
  return combs[a][b] = out % modder;
}
//comber(n, r);
