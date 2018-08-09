#pragma optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#ifdef Wavator
#define debug(fmt, ...) fprintf(stderr, "func[%s] line %d: %s = " fmt "\n", \
                __func__, __LINE__, #__VA_ARGS__, __VA_ARGS__), fflush(stderr)
#define err(x) cerr << "func[" << __func__ << "] line " << __LINE__ << ": " \
                    << #x << " = " << x << endl << flush
#else
#define debug(...) 99
#define err(x) 99
#endif
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const ll mod = (ll)1e9 + 7;
const db eps = 1e-7;
ll pow_mod(ll a, ll b) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}
int ans[500002];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int n;
    cin >> n;
    per(i,0,n){
        if(ans[i])continue;
        int l=0;
        while((1 << l) <= i)++l;
        ans[i]= ((1 << l) - 1)&(~i);
        ans[((1 << l) - 1)&(~i)]=i;
    }
    rep(i,0,n)printf("%d%c",ans[i]," \n"[i==n-1]);
    return 0;
}