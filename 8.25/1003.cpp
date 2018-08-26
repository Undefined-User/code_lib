#pragma optimize("-O3")
#include <bits/stdc++.h>
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
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        rep (i, 0, n) {
            rep (j, 0,  n) {
                int now = i + j;
                printf("%d%c", now%n, " \n"[j == n - 1]);
            }
        }
        rep (i, 0, n)
            rep (j, 0, n)
            {
                ll now = 1ll * i * j;
                printf("%lld%c", now % n, " \n"[j == n - 1]);
            }
    }
    return 0;
}
