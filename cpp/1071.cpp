//1071
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
void solve() {
    lli(y); lli(x);
    ll layer = max(x,y);
    ll offset = min(x,y);
    ll parity = layer&1;
    ll res = layer*layer;
    if (parity) {
        res+=(x+1-y-layer);
    } else {
        res+=(1+y-x-layer);
    }
    p(res)
}
int main() {
    fio
    ii(t);
    for (int i=0;i<t;++i) solve();
}