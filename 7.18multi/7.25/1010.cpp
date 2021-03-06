#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__),fprintf(stderr, "\n"),fflush(stderr)
#else
#define debug(...) 98
#endif
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const ll mod = (ll)1e9+7;
#define scanf ______
//#define gc getchar
inline char gc() { static char buf[1<<20], *head = buf, *tail = buf;return (head == tail && (tail = (head = buf) + fread(buf, 1, 1 << 20, stdin), head == tail)? -1: *head++); }
template <typename T> inline bool read(T &x){ static bool f;static char c;for (c = gc(), f = false; !isdigit(c); c = gc()) { if (c == EOF)return false; else if (c == 45)f = true; }for (x=0;isdigit(c);c=gc())x = x * 10 + c - 48;if (f)x = -x;return true; }
template <typename A, typename B> inline bool read(A&a,B&b){return read(a)&&read(b);}
template <typename A, typename B, typename C> inline bool read(A&a,B&b,C&c){return read(a)&&read(b)&&read(c);}
ll pow_mod(ll a, ll b = mod - 2) { assert(b>=0);ll res=1;for(a%=mod;b;b>>=1,a=a*a%mod)if(b&1)res=res*a%mod;return res; }
/*
 * head
 */
const int N = 100010;

ll a[N];
pair<ll,int> num[N];
ll temp[N << 1];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ll n, x, y;
    while (read(n,x,y)) {
        rep(i,1,n+1)read(a[i]);
        rep(i,1,n+1)num[i].fi=a[i],num[i].se=i;
        ll ans=0;
        memset(temp,0,sizeof(temp));
        sort(num+1,num+n+1);
        reverse(num+1,num+1+n);
        for(int i = 1; i <= n; i++) {
            for(int p = num[i].se; p <= n; p += p&-p) temp[p]++;
            for(int p = num[i].se - 1; p; p -= p&-p) ans += temp[p];
        }
        ans *= min(x, y);
        printf("%lld\n",ans);
    }
    return 0;
}