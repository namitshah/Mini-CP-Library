int pmuts[5001][5001] = {};
bool fpmuts[5001][5001] = {};
int modder = 998244353;

int power(int a, int b)
{
  if(b == 0) return 1;
  long long out = power(a, b / 2);
  out *= out; out %= modder;
  if(b % 2) out *= a;
  return out % modder;
}

int permutator(int a, int b)
{
  if(a == 0 || b == 0)
  return 1;
  if(fpmuts[a][b])
  return pmuts[a][b];
  fpmuts[a][b] = true;
  long long out = permutator(a - 1, b - 1);
  out *= a; out %= modder;
  return pmuts[a][b] = out;
}
//P(n, r)
