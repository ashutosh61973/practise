#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;

void mn_heapify(vector<int> &v, int n, int i)
{
    int mn = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n and v[l] < v[mn])
    {
        mn = l;
    }
    if (r < n and v[r] < v[mn])
    {
        mn = r;
    }
    if (mn != i)
    {
        swap(v[mn], v[i]);
        mn_heapify(v, n, mn);
    }
    return;
}
void build_heap(vector<int> &v)
{
    for (int i = v.size() / 2 - 1; i >= 0; i--)
    {
        mn_heapify(v, v.size(), i);
    }
    return;
}
void replace_root(vector<int> &v, int x)
{
    v[0] = x;
    mn_heapify(v, v.size(), 0);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // memset(prime, true, sizeof(prime));
    //primes(); // primes under 1lakh

    /*
  #ifdef NCR
        init();
    #endif
*/
    int k;
    cin >> k;
    vector<int> v;

    int stop = -1;
    while (1)
    {
        int x;
        cin >> x;
        if (x == stop)
        {
            return 0;
        }
        if (v.size() < k - 1)
        {
            v.push_back(x);
        }
        else if (v.size() == k - 1)
        {
            v.push_back(x);
            build_heap(v);
            cout << v[0] << endl;
        }
        else
        {
            if (x > v[0])
            {
                replace_root(v, x);
            }
            cout << v[0] << endl;
        }
    }
}
