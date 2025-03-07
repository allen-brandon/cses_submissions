//1072
using namespace std;
#include <iostream>
#include <vector>
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define p(_) cout << _ << '\n';
#define pa(_) for (const auto& x : _) cout << x << ' '; cout << '\n';
#define ii(_) int _; cin >> _;
#define lli(_) ll _; cin >> _;
ll solve(ll n) {
    ll m = n*n;
    ll res = 0;
    //center
    res+=(n-4)*(n-4)*(m-9);
    //inner sides
    res+=4*(n-4)*(m-7);
    //inner corner
    res+=4*(m-5);
    //outer sides
    res+=4*(n-4)*(m-5);
    //diagonal corners
    res+=8*(m-4);
    //corners
    res+=4*(m-3);
    return res/2;
}
int main() {
    fio
    lli(n);
    vll v = {0,6,28,96};
    if (n < 4) {
        v.resize(n);
    } else {
        for (ll i=5;i<=n;++i) {
            v.push_back(solve(i));
        }
    }
    for (ll x : v) p(x);
}