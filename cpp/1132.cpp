using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
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

int main() {
    ii(n);
    vector<vi> adj(n+1);
    for (int i=1; i<n; ++i) {
        ii(u); ii(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pair<int,int>> paths(n+1);
    function<void(int,int)> down = [&](int u, int p) {
        int lngst = 0, snd = 0;
        for (int v : adj[u]) {
            if (v==p) continue;
            down(v,u);
            int v_path = paths[v].first+1;
            if (v_path>lngst) {
                snd=lngst;
                lngst=v_path;
            } else if (v_path>snd) {
                snd=v_path;
            }
        }
        paths[u] = {lngst,snd};
    };
    down(1,0);
    function<void(int,int)> up = [&](int u, int p) {
        int path_up = paths[p].first==paths[u].first+1 ? paths[p].second : paths[p].first;
        if (p) path_up+=1;
        auto [lngst, snd] = paths[u];
        if (path_up>lngst) {
            snd = lngst;
            lngst = path_up;
        } else if (path_up > snd) {
            snd = path_up;
        }
        paths[u] = {lngst, snd};
        for (int v : adj[u]) {
            if (v==p) continue;
            up(v,u);
        }
    };
    up(1,0);
    vi res(n);
    transform(paths.begin()+1, paths.end(), res.begin(), [](auto &p) { return p.first; });
    printv(res);
}
