//while (clock()<=4.9*CLOCKS_PER_SEC)
#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#ifndef Wavator
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#define unordered_map __gnu_pbds::cc_hash_table
#endif
using namespace std;
#ifdef Wavator
#include "local_debug.h"
#else
#define debug(...)
#endif
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr db PI = acos(-1), eps = 1e-8;
constexpr ll mod = (ll)1e9 + 7;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);
    ll res = 1;
    for (a %= mod; b; b >>= 1, a = a * a % mod) {
        if (b & 1) {
            res = res * a % mod;
        }
    }
    return res;
}
const int offset = 100;
const int N = 1005;
int a[N], b[N], c[N], n;
int dp[N][(offset + 2) << 1];
bool vis[N][(offset + 1) << 1];
int dfs(int now, int v) {
    if (now > n) {
        return v;
    }
    if (vis[now][v + offset]) {
        return dp[now][v + offset];
    }
    vis[now][v + offset] = 1;
    vi res;
    if (a[now]) {
        res.pb(dfs(now + 1, min(v + a[now], offset)));
    }
    if (b[now]) {
        res.pb(dfs(now + 1 ,max(v - b[now], -offset)));
    }
    if (c[now]) {
        res.pb(dfs(now + 1, -v));
    }
    return dp[now][v + offset] = (now & 1)? *max_element(all(res)): *min_element(all(res));
}

int main() {
    scanf("%d", &n);
    int m, k, l;
    scanf("%d%d%d", &m, &k, &l);
    for (int i = 1; i <= n; ++i) scanf("%d%d%d", a + i, b + i, c + i);
    if (dfs(1, m) <= l) {
        puts("Bad Ending");
    } else if (dfs(1, m) >= k) {
        puts("Good Ending");
    } else {
        puts("Normal Ending");
    }
    return 0;
}