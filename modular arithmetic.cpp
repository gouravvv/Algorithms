const ll N = 1e5;
const ll MOD = 1e9+7;

ll add(ll x, ll y) {ll ans = x + y; return (ans >= MOD ? ans - MOD : ans);}
ll mul(ll x, ll y) {ll ans = x * y; return (ans >= MOD ? ans % MOD : ans);}
ll sub(ll x, ll y) {ll ans = x - y; return (ans < 0 ? ans + MOD : ans);}

vector<ll> fac, fac_inverse, num_inverse;

void preprocess() {
  fac = fac_inverse = num_inverse = vector<ll>(N + 1);
  num_inverse[0] = num_inverse[1] = 1;
  for (ll i = 2; i <= N; i++)
    num_inverse[i] = num_inverse[MOD % i] * (MOD - MOD / i) % MOD;
  fac_inverse[0] = fac_inverse[1] = 1;
  for (ll i = 2; i <= N; i++)
    fac_inverse[i] = (num_inverse[i] * fac_inverse[i - 1]) % MOD;
  fac[0] = 1;
  for (ll i = 1; i <= N ; i++)
    fac[i] = (fac[i - 1] * i) % MOD;
}

ll power(ll x, ll y)
{
  ll ans = 1;
  x = x % MOD;
  while (y > 0) {
    if (y & 1)
      ans = (ans * x) % MOD;

    y = y >> 1;
    x = (x * x) % MOD;
  }
  return ans;
}

ll modInverse(ll n)
{
  return power(n, MOD - 2);
}

ll nCr( ll n, ll r)
{
  if (r == 0)
    return 1;

  return mul(mul(fac[n], fac_inverse[r]), fac_inverse[n - r]);
}
