#include <bits/stdc++.h>
#pragma optimize("-O3")
using namespace std;
template <typename A, typename B> inline ostream& operator << (ostream&os, const pair<A, B> &v) {
    return os << v.first << ' ' << v.second;
}
template <typename T> inline ostream& operator << (ostream&os, const vector<T> &v) {
    for (auto it = v.begin(); it != v.end(); os << (*it++)) if (it != v.cbegin()) os << '\n';
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
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int N = 100005;
char s[N];
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    scanf("%s", s);
    int n = strlen(s), t = 0, e = 0;
    rep(i, 0, n)
        t+=(s[i]=='1');
    rep(i, 0, n) {
        if(s[i]=='0')
            putchar(48);
        else if(s[i]=='2') {
            if(!e) {
                while(t--)
                    putchar(49);
                e=1;
            }
            putchar(50);
        }
    }
    if(!e)
        for (; t--; ) putchar(49);
    return 0;
}