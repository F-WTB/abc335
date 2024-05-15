#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<int, int>;
ostream &operator<<(ostream &os, const mint &x)
{
    os << x.val();
    return os;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
struct fast
{
    fast()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;

const int B = 64;
int N, A;
mint dp[200000] = {1}, v[B][B];

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> A;
        for (int x = 1; x < B; ++x)
            dp[i] += v[x][i % x];
        if (A < B)
            v[A][i % A] += dp[i];
        else
            for (int x = i + A; x < N; x += A)
                dp[x] += dp[i];
    }
    mint ans = 0;
    for (int i = 0; i < N; ++i)
        ans += dp[i];
    cout << ans << '\n';
}
