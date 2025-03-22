//1623
using namespace std;
#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define counter(_) unordered_map<_,size_t>
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define p(_) cout << _ << '\n';
#define pv(_) for (const auto& x : _) cout << x << ' '; cout << '\n';
#define pum(_) cout<<"{";for (const auto& kvp:_) cout<<kvp.first<<":"<<kvp.second<<","; cout<<"}\n";
#define si(_) string _; cin >> _;
#define ii(_) int _; cin >> _;
#define lli(_) ll _; cin >> _;
int inf = 1000000007;

int main() {
    fio;
    ii(n);
    vi v(n);
    for (int i=0;i<n;++i) {
        cin >> v[i];
    }
    ll msf = inf;
    for (int mask=1;mask<1<<n;++mask) {
        int tmp = mask;
        ll cur = 0;
        for (int j=0;j<n;++j) {
            cur+=tmp&1?v[j]:-v[j];
            tmp>>=1;
        }
        msf = min(msf,abs(cur));
    }
    p(msf);
}