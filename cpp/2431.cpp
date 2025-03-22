//2431
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#define ll long long
#define ull unsigned ll
#define vll vector<ll>
#define vi vector<int>
#define counter(_) unordered_map<_,size_t>
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define p(_) cout << _ << "\n";
#define pv(_) for (const auto& x : _) cout << x << ' '; cout << '\n';
#define pum(_) cout<<"{";for (const auto& kvp:_) cout<<kvp.first<<":"<<kvp.second<<","; cout<<"}\n";
#define si(_) string _; cin >> _;
#define ii(_) int _; cin >> _;
#define lli(_) ll _; cin >> _;
int inf = 1000000007;

char solve(ull k) {
    k-=1;
    ull x = 1;
    ull i = 1;
    ull t = 1;
    while (t*9*i <= k) {
        k-=t*9*i;
        x+=t*9;
        ++i;
        t*=10;
    }
    x+=k/i;
    k%=i;
    return to_string(x)[k];
}

int main() {
    ii(q);
    ull k;
    for (int i=0; i<q; ++i) {
        cin >> k;
        p(solve(k));
    }
}