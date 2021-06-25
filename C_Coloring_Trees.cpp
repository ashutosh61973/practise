#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;

bool prime[100000]; //primes under 10^5
//////////////////////////////////seive for prime/////////////////////////////
/*
void primes() 
{ 
  int n=100000;
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
        // Print all prime numbers 
           // for (int p=2; p<=n; p++) 
        // if (prime[p]) 
         // cout << p << " "; 
} 
*/
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////NCR////////////////////////////////////////
/*const int N=5000;
 
#define NCR
#define PRIME	M
inti pw(inti a,inti p=M-2,inti MOD=M){
    inti result = 1;
    while (p > 0) {
        if (p & 1)
            result = a * result % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return result;
}
inti fact[N],invfact[N];
void init(){
    inti p=PRIME;
    fact[0]=1;
    inti i;
    for(i=1;i<N;i++){
        fact[i]=i*fact[i-1]%p;
    }
    i--;
    invfact[i]=pw(fact[i],p-2,p);
    for(i--;i>=0;i--){
        invfact[i]=invfact[i+1]*(i+1)%p;
    }
}
inti ncr(inti n,inti r){
    if(r > n || n < 0 || r < 0)return 0;
    return fact[n]*invfact[r]%PRIME*invfact[n-r]%PRIME;
}*/
///////////////////////////////////////////////////////////////////////////////

////\\//////\\/////////\\///////////\\\////////\\/////////////\\\/////
/*
ll power(ll a, ll b) //time complexity is  o(log(b));
{
  if (a == 0)
    return 0;
  ll ans = 1;
  a = a % mod;
  while (b > 0)
  {
    if ((b & 1) == 1)
      ans = (ans * a) % mod;
    b = b >> 1;
    a = (a * a) % mod;
  }
  return ans;
}*/
//\\////\\//////\\//////\//////\\///////\\//////////\\/////\\///
/*bool isPrime(int n) {
 
  if (n == 1) {
    return false;
  }
 
  for (int i = 2; i*i <= n; i++) {
    if (n % i == 0) return false;
  }
 
  return true;
}*/
//////////////\\\\\\\\////////\\\\\\\\\\//////////\\\\////

///////////////////////////////////////////////////////////////////////

/*
//sort string by there length ==>

sort(v.begin(), v.end(), [&] (const string &s, const string &t) {
        return s.size() < t.size();
    });
*/

///////////////////////////////////////////////////////////////////////
ll dp[120][120][120];
ll f(int i, int n, int m, int k, int prev, vector<ll> &c, vector<vector<ll>> &p)
{
    if (i == (n + 1) and k == 0)
    {
        return 0;
    }
    if (i == (n + 1))
    {
        return (1e15) * 1ll;
    }
    if (dp[i][k][prev] != -1)
    {
        return dp[i][k][prev];
    }
    if (c[i] != 0)
    {
        if (i != 1)
        {
            return dp[i][k][prev] = 0 * 1ll + f(i + 1, n, m, k - (c[i] != prev), c[i], c, p);
        }
        return dp[i][k][prev] = 0 * 1ll + f(i + 1, n, m, k - (1 * 1ll), c[i], c, p);
    }
    ll ans = (1e15) * 1ll;

    for (int j = 1; j <= m; j++)
    {
        if (j == prev)
        {
            ans = min(ans, p[i][j] + f(i + 1, n, m, k, j, c, p));
        }
        else
        {
            ans = min(ans, p[i][j] + f(i + 1, n, m, k - 1, j, c, p));
        }
    }
    return dp[i][k][prev] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //primes(); // primes under 1lakh

    /*
  #ifdef NCR
        init();
    #endif
*/
    memset(dp, -1 * 1ll, sizeof(dp));
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> c(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i + 1];
    }

    vector<vector<ll>> p(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> p[i][j];
        }
    }
    ll ans = f(1, n, m, k, 0, c, p);
    if (ans == (1e15) * 1ll)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}
