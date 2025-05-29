#include<bits/stdc++.h>
using namespace std;

long long modder = 1e+9 + 7;
int fast_mod(const __int128 input) {
    // apply the modulo operator only when needed
    // (i.e. when the input is greater than the ceiling)
    return input >= modder ? input % modder : input;
    // NB: the assumption here is that the numbers are positive
}
vector<vector<long long>> mult
(vector<vector<long long>> &a,
vector<vector<long long>> &b)
{
  vector<vector<long long>> out(2, vector<long long>(2));
  out[0][0] = fast_mod((__int128)a[0][0] * b[0][0] +
  (__int128)a[0][1] * b[1][0]);
  out[0][1] = fast_mod((__int128)a[0][0] * b[0][1] +
  (__int128)a[0][1] * b[1][1]);
  out[1][0] = fast_mod((__int128)a[1][0] * b[0][0] +
  (__int128)a[1][1] * b[1][0]);
  out[1][1] = fast_mod((__int128)a[1][0] * b[0][1] +
  (__int128)a[1][1] * b[1][1]);
  return out;
}

vector<vector<long long>>
acolyte(long long power)
{
  vector<vector<long long>> iden = {{1, 0}, {0, 1}},
  unit = {{1, 1}, {1, 0}};
  if(power == 0) return iden;
  auto out = acolyte(power / 2);
  out = mult(out, out);
  if(power % 2) out = mult(out, unit);
  return out;
}
void processor()
{
  long long n; cin >> n;
  long long out = (acolyte(n + 2)[0][1] - 1);
  if(out < 0) out += modder;
  cout << out << "\n";
  return;
}

/*WhAt ArE dAyS fOr?|----|DaYs ArE wHeRe We LiVe */
/*ThEy CoMe, ThEy WaKe Us|---|TiMe AnD tImE oVeR.*/
/*ThEy--*/int main()
/*aRe tO*/{
/*bE HaP*/  ios_base::sync_with_stdio(false);
/*pY iN.*/  cin.tie(NULL);
/*wHeRe */  int count, counter = 0;
/*cAn wE*/  cin >> count;
/*lIvE b*/  while(counter++ < count)
/*Ut dAy*/  {processor();}
/*S. aH,*/  return 0;
/*sOlViN*/}
/*g tHaT qUeStIoN bRiNgS tHe PrIeSt AnD tHe DoCt */
/*Or In ThEiR lOnG cOatS RuNnInG oVeR tHe FiElDs.*/
