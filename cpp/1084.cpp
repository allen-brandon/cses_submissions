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

// 1084
int main() {
    fio;
    ii(n);ii(m);ii(k);
    vi a(n); for (int i=0;i<n;++i) cin >> a[i];
    vi b(m); for (int i=0;i<m;++i) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int j = 0, res = 0;
    for (int i = 0; i<n and j<m; ++i) {
        while (j<m && b[j]<a[i]-k) ++j;
        if (j<m && b[j]<=a[i]+k) {
            ++j;
            ++res;
        }
    }
    print(res)
}