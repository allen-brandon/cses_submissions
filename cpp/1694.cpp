using namespace std;
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <deque>
#include <queue>
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
ll inf = 151515151515151;
ll mod = 1000000007;

array<array<ll, 501>, 501> flow_graph;
array<array<ll, 501>, 501> graph;
array<int, 501> level;
array<int, 501> seen;

int main() {
    fio;
    ii(n); ii(m);
    ll res = 0;
    for (int i=1; i<=n; ++i) {
        fill(graph[i].begin(), graph[i].begin()+n+1, 0ll);
        fill(flow_graph[i].begin(), flow_graph[i].begin()+n+1, 0ll);
    }
    vector<set<int>> adj(n+1);
    for (int i=0;i<m;++i) {
        ii(u); ii(v); lli(w);
        graph[u][v]+=w;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int u, v;
    bool found;
    for (int step = 0; step < inf; ++step) {
        fill(level.begin(), level.begin()+n+1, 0);
        fill(seen.begin(), seen.begin()+n+1, 0);
        queue<int> q;
        q.push(1);
        found = false;
        while (!found && q.size()!=0) {
            u = q.front();
            q.pop();
            for (auto v : adj[u]) {
                if (!graph[u][v] || seen[v]!=0) continue;
                seen[v] = u;
                if (v==n) found = true;
                q.push(v);
                if (found) break;
            }
        }
        if (!found) break;
        v = n;
        ll flow = inf;
        while (v!=1) {
            u = seen[v];
            flow = min(flow, graph[u][v]);
            v = u;
        }
        res+=flow;
        v = n;
        while (v!=1) {
            u = seen[v];
            graph[u][v]-=flow;
            graph[v][u]+=flow;
            flow_graph[u][v]+=flow;
            flow_graph[v][u]-=flow;
            v = u;
        }
    }

    print(accumulate(flow_graph[1].begin(), flow_graph[1].end(), 0ll));
}