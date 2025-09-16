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
array<string,2> ny = {"NO","YES"};
ll inf = 151515151515151;
ll mod = 998244353;
array<vi,100001> adj;
bitset<100001> seen;
bitset<100001> path;

int main() {
    USE_INPUT_FILE("_input.txt");
    fio;
    ii(n); ii(m);
    fill_n(adj.begin(), n+1, vi());
    fr(i,0,n+1) path[i]=0;
    fr(i,0,m) {
        ii(u); ii(v);
        adj[u].push_back(v);
    }
    vi res;
    bool found = false;
    stack<pair<int,int>> st;
    fr(i,1,n+1) {
        if (seen[i]) continue;
        seen[i] = 1;
        st.emplace(i,1);
        while (!found && !st.empty()) {
            auto [u,d] = st.top();
            st.pop();
            if (d==0) {
                path[u]=0;
                res.pop_back();
                continue;
            }
            path[u] = 1;
            res.push_back(u);
            st.emplace(u,0);
            for (auto v : adj[u]) {
                if (path[v]) {
                    found = true;
                    res.push_back(v);
                    break;
                }
                if (seen[v]) continue;
                seen[v] = 1;
                st.emplace(v,1);
            }
        }
        if (found) break;
    }
    if (res.empty()) {
        print("IMPOSSIBLE");
    } else {
        fr(i,0,res.size()) {
            if (res[i]==res.back()) {
                res.erase(res.begin(), res.begin()+i);
                break;
            }
        }
        print(res.size());
        printv(res);
    }
}