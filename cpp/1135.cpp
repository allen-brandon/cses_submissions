#ifdef LOCAL
#include "_pch.hpp"
#define USE_INPUT_FILE(file) freopen(file, "r", stdin);
#else
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define USE_INPUT_FILE(file)
#endif

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long;
#define vll vector<ll>
#define vi vector<int>
#define counter(_) unordered_map<_,size_t>
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> // find_by_order(), order_of_key()
#define ordered_multiset tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fr(i,l,r) for (int i=l; i<r; ++i)
#define print(_) cout << _ << "\n";
#define printv(_) for (const auto& x : _) cout << x << ' '; cout << '\n';
#define printm(_) cout<<"{";for (const auto& kvp:_) cout<<kvp.first<<":"<<kvp.second<<","; cout<<"}\n";
#define si(_) string _; cin >> _;
#define ii(_) int _; cin >> _;
#define lli(_) ll _; cin >> _;
array<pair<int,int>,4> didj = {{{-1,0},{0,1},{1,0},{0,-1}}};
array<string,2> ny = {"No","Yes"};
ll inf = 151515151515151;
ll mod = 998244353;
int res[200001];
int depth[200001];
int tour[200001][2];
int anc[200001][20];
array<vi,200001> adj;

int main() {
    USE_INPUT_FILE("_input.txt");
    fio;
    ii(n); ii(q);
    fill_n(adj.begin(), n+1, vi());
    fr(i,0,n-1) {
        ii(u); ii(v);
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int tour_idx = 0;
    int* i = &tour_idx;
    auto assign = [](auto& assign, int u, int p, int d, int* i) -> void {
        anc[u][0] = p;
        fr(j,1,20) {
            if (anc[u][j-1] == 0) break;
            anc[u][j] = anc[anc[u][j-1]][j-1];
        }
        depth[u] = d;
        tour[u][0] = *i;
        ++(*i);
        for (int& v : adj[u]) {
            if (v==p) continue;
            assign(assign,v,u,d+1,i);
        }
        tour[u][1] = *i;
        ++(*i);
    };
    assign(assign, 0, 0, 0, i);
    fr(i,0,q) {
        ii(u); ii(v);
        --u; --v;
        if (depth[u]>depth[v]) swap(u,v);
        auto [l,r] = tour[v];
        if (tour[u][0]<=l && tour[u][1]>=r) {
            res[i] = depth[v]-depth[u];
            continue;
        }
        int x = u;
        for (int j=19; j>=0; --j) {
            int y = anc[x][j];
            if (tour[y][0]>l || tour[y][1]<r) x = y;
        }
        x = anc[x][0];
        res[i] = depth[u]+depth[v]-(depth[x]*2);
    }
    fr(i,0,q) print(res[i]);
}