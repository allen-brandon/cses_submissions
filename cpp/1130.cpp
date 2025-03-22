using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <deque>
#include <numeric>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define ull unsigned ll
#define vll vector<ll>
#define vi vector<int>
#define counter(_) unordered_map<_,size_t>
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define print(_) cout << _ << "\n";
#define printv(_) for (const auto& x : _) cout << x << ' '; cout << '\n';
#define printum(_) cout<<"{";for (const auto& kvp:_) cout<<kvp.first<<":"<<kvp.second<<","; cout<<"}\n";
#define si(_) string _; cin >> _;
#define ii(_) int _; cin >> _;
#define lli(_) ll _; cin >> _;
ll inf = 1000000007;
ll mod = 1000000007;

// 1130
int main() {
    fio;
    ii(n);
    vector<vi> adj(n+1);
    for (int i=1; i<n; ++i) {
        ii(u); ii(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    function<pair<int,int>(int,int)> dfs = [&adj, &dfs](int u,int p) -> pair<int,int> {
        int take=0, dont=0;
        for (int v : adj[u]) {
            if (v==p) continue;
            auto [v_take, v_dont] = dfs(v,u);
            take = max(take, v_dont+1-v_take);
            dont+=v_take;
        }
        return {take+dont,dont};
    };
    auto [x, y] = dfs(1,0);
    print(max(x,y));
}