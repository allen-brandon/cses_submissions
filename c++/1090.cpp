using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#define ll long long
#define ull unsigned ll
#define vll vector<ll>
#define vi vector<int>
#define counter(_) unordered_map<_,size_t>
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define print(_) cout << _ << "\n";
#define printv(_) for (const auto& x : _) cout << x << ' '; cout << '\n';
#define printum(_) cout<<"{";for (const auto& kvp:_) cout<<kvp.first<<":"<<kvp.second<<","; cout<<"}\n";
#define si(_) string _; cin >> _;
#define ii(_) int _; cin >> _;
#define lli(_) ll _; cin >> _;
int inf = 1000000007;

// 1090
int main() {
    fio;
    ii(n);ii(x)
    vi v(n); for (int i=0;i<n;++i) cin >> v[i];
    sort(v.begin(), v.end(),greater<int>());
    int l, r = n-1;
    for (l = 0; l<=r; ++l) {
        if (v[l]+v[r]<=x) r-=1;
    }
    print(l);
}