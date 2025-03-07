//1092
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
int main() {
    fio
    lli(n);
    if (0<n%4 && n%4<3) {
        p("NO");
        return 0;
    }
    p("YES");
    vll v1;vll v2;
    unordered_map<ll,ll> seen;
    ll target = (n*(n+1))/4;
    ll cur = 0;
    for (ll i=1;i<=n;++i) {
        cur+=i;
        seen[cur]=i;
        if (seen.find(cur-target) != seen.end()) {
            ll j = seen[cur-target];
            for (ll k=1;k<=j;++k) v1.push_back(k);
            for (ll k=j+1;k<=i;++k) v2.push_back(k);
            for (ll k=i+1;k<=n;++k) v1.push_back(k);
            p(v1.size());
            pv(v1);
            p(v2.size());
            pv(v2);
            return 0;
        }
    }
}