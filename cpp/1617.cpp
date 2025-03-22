//1617
using namespace std;
#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define p(_) cout << _ << '\n';
#define pv(_) for (const auto& x : _) cout << x << ' '; cout << '\n';
#define ii(_) int _; cin >> _;
#define lli(_) ll _; cin >> _;
ll mod = 1000000007;

ll modpow(ll base, ll exp, ll mod) {
    base%=mod;
    ll res=1;
    while (exp>0) {
        if (exp&1) res=(res*base)%mod;
        base=(base*base)%mod;
        exp>>=1;
    }
    return res;
}
int main() {
    fio
    ii(n);
    ll ret = modpow(2,n,mod);
    p(ret);
}