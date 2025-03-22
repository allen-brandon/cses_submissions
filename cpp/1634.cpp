using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <deque>
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
ll inf = 1000000007;
ll mod = 1000000007;

// 1634
int main() {
    fio;
    ii(n);ii(x);
    vi v(n); for (int i=0;i<n;++i) cin >> v[i];
    deque<int> q = {0};
    vi seen(x+1);
    int depth = 0;
    while (q.size() && !seen[x]) {
        size_t c = q.size();
        for (int i=0;i<c;++i) {
            int u = q[0];
            q.pop_front();
            for (const auto& y : v) {
                if (u+y>x || seen[u+y]) continue;
                seen[u+y]=1;
                q.push_back(u+y);
            }
        }
        ++depth;
    }
    if (q.size()) {
        print(depth);
    } else print(-1);
}