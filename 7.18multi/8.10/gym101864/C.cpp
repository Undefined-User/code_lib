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
int a[200];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int T;
    scanf("%d",&T);
    for (int k=1;k<=T;++k){
        int n, m;
        scanf("%d%d",&m,&n);
        int s=0;
        for(int i=1;i<=n;++i)scanf("%d",a+i),s+=a[i];
        bool f=0;
        for(int i=2;i<=n;++i)if(a[i]-a[i-1]==1){
                f=1;
            }
        printf("Case %d: Thank You BACS!!! %s",k,s==m?"Thik ache.":"Bojjat dokandar!!");
        puts(f?" Yes":" No");
    }
    return 0;
}