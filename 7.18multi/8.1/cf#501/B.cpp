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
ll pow_mod(ll a, ll b) {
    assert(b >= 0);ll res=1;
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    string s, t;
    vector<int> ans;
    cin >> n >> s >> t;
    for (int i = 0; i < n; ++i){
        int idx=-1;
        for(int j = i;j < n;j++) if(s[j]==t[i]) {idx=j; break;}
        if(idx==-1)
        {
            puts("-1");
            return 0;
        }
        for(int j=idx;j>i;j--)
        {
            ans.push_back(j);
            swap(s[j],s[j-1]);
        }
    }
    cout << ans.size() << endl;
    for(int i=0;i<(int)ans.size();i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}