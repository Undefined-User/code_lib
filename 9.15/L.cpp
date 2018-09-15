//while (clock()<=4.9*CLOCKS_PER_SEC)
#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

//typedef long long ll;
//constexpr ll mod = (ll)1e9 + 7;
//ll pow_mod(ll a, ll b) {
//    ll res = 1;
//    for (a %= mod; b; b >>= 1, a = a * a % mod) {
//        if (b & 1) {
//            res = res * a % mod;
//        }
//    }
//    return res;
//}
struct mat {
    static const int siz = 10;
    ll a[siz][siz];
    int n, m;

    mat(int _n, int _m) {
        n = _n, m = _m;
        for (int i = 0; i < n; i++)
            fill(a[i], a[i] + m, 0);
    }

    void dig() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = (i == j);
            }
        }
    }

    ll *operator[](const int x) {
        return a[x];
    }

    mat operator+(const mat &b) const {
        mat ret(n, m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ret[i][j] = a[i][j] + b.a[i][j];
                if (ret[i][j] >= mod) {
                    ret[i][j] -= mod;
                }
            }
        }
        return ret;
    }

    mat operator-(const mat&b) const {
        mat ret(n, m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ret[i][j] = a[i][j] - b.a[i][j];
                if (ret[i][j] < 0) {
                    ret[i][j] += mod;
                }
            }
        }
        return ret;
    }

    mat operator*(const mat &b) const {
        mat ret(n, b.m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < b.m; j++)
                for (int k = 0; k < m; k++) {
                    ll t = (ll) a[i][k] * b.a[k][j];
                    if (t >= mod)
                        t %= mod;
                    ret[i][j] += t;
                    if (ret[i][j] >= mod)
                        ret[i][j] -= mod;
                }
        return ret;
    }

    mat operator^(long long k) const {
        mat ret(n, m), b = *this;
        for (int i = 0; i < n; ++i)ret[i][i] = 1;
        for (; k; k >>= 1, b = b * b) {
            if (k & 1)
                ret = ret * b;
        }
        return ret;
    }

    ll delta() {
        ll res = 1;
        for (ll i = 0; i < n; i++) {
            for (ll j = i; j < n; j++) {
                if (a[j][i] != 0) {
                    for (ll k = i; k < n; k++) {
                        swap(a[i][k], a[j][k]);
                    }
                    if (i != j) {
                        res = (-res + mod) % mod;
                    }
                    break;
                }
            }
            if (a[i][i] == 0) {
                res = 0;//������
                break;
            }
            for (ll j = i + 1; j < n; j++) {
                ll mut = (a[j][i] * pow_mod(a[i][i], mod - 2)) % mod;
                for (ll k = i; k < n; k++) {
                    a[j][k] = (a[j][k] - (a[i][k] * mut) % mod + mod) % mod;
                }
            }
            res = (res * a[i][i]) % mod;
        }
        return res;
    }

    void get_matrix_tree(int n, int g[siz][siz]) {
        *this = mat(n, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][i] += g[i][j];
                a[i][j] -= g[i][j];
            }
        }
    }


    ll inv(ll x) {
        return pow_mod(x, mod - 2);
    }

    mat get_inv() {
        mat b(n, m);
        b.dig();
        for (int i = 0, j; i < n; i++) {
            for (int k = i; k < n; k++)
                if (a[k][i]) {
                    j = k;
                    break;
                }
            if (i != j) {
                for (int k = 0; k < n; k++) {
                    swap(a[i][k], a[j][k]);
                    swap(b.a[i][k], b.a[j][k]);
                }
            }
            for (j = i + 1; j < n; j++) {
                int d = a[j][i] * inv(a[i][i]) % mod;
                for (int k = 0; k < n; k++) {
                    a[j][k] = (a[j][k] - a[i][k] * d) % mod;
                    b.a[j][k] = (b.a[j][k] - b.a[i][k] * d) % mod;
                    if (a[j][k] < 0) a[j][k] += mod;
                    if (b.a[j][k] < 0) b.a[j][k] += mod;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            int d = inv(a[i][i]);
            for (int k = 0; k < n; k++) {
                a[i][k] = a[i][k] * d % mod;
                b.a[i][k] = b.a[i][k] * d % mod;
            }
            for (int j = i - 1; j >= 0; j--) {
                d = a[j][i] * inv(a[i][i]) % mod;
                for (int k = 0; k < n; k++) {
                    a[j][k] = (a[j][k] - a[i][k] * d) % mod;
                    b.a[j][k] = (b.a[j][k] - b.a[i][k] * d) % mod;
                    if (a[j][k] < 0) a[j][k] += mod;
                    if (b.a[j][k] < 0) b.a[j][k] += mod;
                }
            }
        }
        return b;
    }

};
mat Strassen(mat A, mat B) {
    if (A.n == 1) return A * B;
    mat C(A.n, B.m);
    int mid = A.n >> 1;
    mat A11(mid, mid);
    mat A12(mid, mid);
    mat A21(mid, mid);
    mat A22(mid, mid);
    mat B11(mid, mid);
    mat B12(mid, mid);
    mat B21(mid, mid);
    mat B22(mid, mid);
    mat P1(mid, mid);
    mat P2(mid, mid);
    mat P3(mid, mid);
    mat P4(mid, mid);
    mat P5(mid, mid);
    mat P6(mid, mid);
    mat P7(mid, mid);
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            B11[i][j] = B[i][j];
        }
    }
    for (int i = mid; i < A.n; i++) {
        for (int j = 0; j < mid; j++) {
            A12[i - mid][j] = A[i][j];
            B12[i - mid][j] = B[i][j];
        }
    }
    for (int i = 0; i < mid; i++) {
        for (int j = mid; j < A.n; j++) {
            A21[i][j - mid] = A[i][j];
            B21[i][j - mid] = B[i][j];
        }
    }
    for (int i = mid; i < A.n; i++) {
        for (int j = mid; j < A.n; j++) {
            A22[i - mid][j - mid] = A[i][j];
            B22[i - mid][j - mid] = B[i][j];
        }
    }
    P1 = Strassen(A11, B12 - B22);
    P2 = Strassen(A11 + A12, B22);
    P3 = Strassen(A21 + A22, B11);
    P4 = Strassen(A22, B21 - B11);
    P5 = Strassen(A11 + A22, B11 + B22);
    P6 = Strassen(A12 - A22, B21 + B22);
    P7 = Strassen(A11 - A21, B11 + B12);
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
        }
    }
    for (int i = mid; i < A.n; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = P1[i - mid][j] + P2[i - mid][j];
        }
    }
    for (int i = 0; i < mid; i++) {
        for (int j = mid; j < A.n; j++) {
            C[i][j] = P3[i][j - mid] + P4[i][j - mid];
        }
    }
    for (int i = mid; i < A.n; i++) {
        for (int j = mid; j < A.n; j++) {
            C[i][j] = P1[i - mid][j - mid] + P5[i - mid][j - mid] - P3[i - mid][j - mid] - P7[i - mid][j - mid];
        }
    }
    return C;
}

int main() {
    mat bs(9, 9);
    bs.a[0][3] = bs.a[0][6] = bs.a[1][0] = bs.a[1][6] = bs.a[2][0] = bs.a[2][3] = bs.a[2][6] = bs.a[3][1] = bs.a[3][4] = bs.a[4][1] = bs.a[4][7] = bs.a[5][4] = bs.a[5][7] = bs.a[6][2] = bs.a[6][5] = bs.a[6][8] = bs.a[7][2] = bs.a[7][8] = bs.a[8][2] = bs.a[8][5] = 1;
    int T;
    for (scanf("%d", &T); T--;) {
        ll n;
        scanf("%lld", &n);
        if (n == 1) puts("3");
        else if (n == 2) puts("9");
        else {
            ll res = 0;
            auto a = bs ^ (n - 2);
            rep(i, 0, 9) {
                rep(j, 0, 9) {
                    res = (res + a[i][j]) % mod;
                }
            }
            printf("%lld\n", res);
        }

    }
    return 0;
}
