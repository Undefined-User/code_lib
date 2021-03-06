#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B> inline ostream& operator << (ostream&os, const pair<A, B> &v) {
    return os << v.first << ' ' << v.second;
}
template <typename T> inline ostream& operator << (ostream&os, const vector<T> &v) {
    for (auto it = v.begin(); it != v.end(); os << (*it++)) if (it != v.cbegin()) os << ' ';
    return os;
}
#ifdef Wavator
#define debug(...) cerr << #__VA_ARGS__ << " = \n[ ", _debug(__VA_ARGS__), cerr << "]" << endl
#else
#define debug(...) 98
#define cerr if (false) cout
#endif
void _debug(){}
template <typename H, typename...T>
void _debug(H head, T...tail) {
    cerr << head << " ";
    _debug(tail...);
}
#define rep(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define per(i, a, b) for (int (i) = (b) - 1; (i) >= (a); --(i))
#define REP(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int oo = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;
class Dinic {
public:
    static const int N = 505;
    struct edge {
        int to, cap, flow;
        edge(int to, int cap): to(to), cap(cap), flow(0){}
    };
    int n, s, t;
    vector<edge> e;
    vector<int> G[N];
    bool vis[N];
    int d[N];
    int cur[N];
    inline void add_edge(int u, int v, int c) {
        //debug(u, v, c);
        G[u].push_back(SZ(e));
        e.push_back(edge(v, c));
        G[v].push_back(SZ(e));
        e.push_back(edge(u, 0));
    }
    inline bool bfs() {
        memset(vis, 0, sizeof(vis));
        static int q[N];
        int head = 0, tail = 0;
        q[tail++] = s;
        d[s] = 0, vis[s] = true;
        for (; tail ^ head;) {
            int u = q[head++];
            for (const int &x: G[u]) {
                edge & now = e[x];
                if (!vis[now.to] && now.cap > now.flow) {
                    vis[now.to] = true;
                    d[now.to] = d[u] + 1;
                    q[tail++] = now.to;
                }
            }
        }
        return vis[t];
    }
    int dfs(int x,int a) {
        if (x == t || a == 0)return a;
        int flow = 0, f;
        for (int &i = cur[x]; i < G[x].size(); i++) {
            edge &now = e[G[x][i]];
            if (d[x] + 1 == d[now.to] && (f = dfs(now.to, min(a, now.cap - now.flow))) > 0) {
                now.flow += f;
                e[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }
    int get_max_flow(int s = -1, int t = -1) {
        if (~s)this->s = s, this->t = t;
        else s = this->s;
        int flow = 0;
        for (;bfs();) {
            memset(cur, 0, sizeof(cur));
            flow += dfs(s, oo);
        }
        return flow;
    }
    void init(int n, int s = 0, int t = 0) {
        this->n = n;
        this->s = s;
        this->t = t;
        for (int i = 0; i <= n; ++i) {
            G[i].clear();
        }
        e.clear();
    }
}dc;
const int maxn = 505;
map<string,int> M;
int cnt_, rec[maxn] , plu[maxn];
int ID(const string &s){
    if(M.count(s)) return M[s];
    return M[s] = cnt_++;
}

int f[maxn],t[maxn];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    int TT;
    for (scanf("%d", &TT); TT--; M.clear()) {
        int n, m, k;
        scanf("%d",&n);
        cnt_ = 1;
        string str, src;
        static char s[50];
        memset(rec, 0, sizeof(rec));
        memset(plu, 0, sizeof(plu));
        REP(i, 1, n) {
            scanf("%s",s); src = s;
            rec[ID(src)]++;
        }
        scanf("%d",&m);
        static char s1[50],s2[50];
        REP(i, 1, m) {
            scanf("%s %s",s1,s2);
            src = s2;
            plu[ID(src)]++;
        }
        scanf("%d",&k);
        REP(i, 1, k) {
            scanf("%s %s",s1,s2);
            str = s1 , src = s2;
            f[i] = ID(str),t[i]=ID(src);
        }
        int S = 0 , T = cnt_;
        dc.init(T);
        rep(i,1,cnt_) if(plu[i]){
            dc.add_edge(S,i,plu[i]);
        }
        rep(i,1,cnt_) if(rec[i]){
            dc.add_edge(i,T,rec[i]);
        }
        REP(i, 1, k) {
            if(f[i] != t[i])
                dc.add_edge(f[i],t[i],oo);
        }
        printf("%d\n",m - dc.get_max_flow(S, T));
        if(TT)putchar(10);
    }
    return 0;
}
