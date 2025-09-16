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
ll mod = 1000000007;
array<vi,100001> adj;
ll dp[100001];
int ind[100001];


int main() {
    USE_INPUT_FILE("_input.txt");
    fio;
    ii(n); ii(m);
    fill_n(adj.begin(),n+1,vi());
    fill_n(dp,n+1,0ll);
    dp[n] = 1;
    fill_n(ind,n+1,0);
    fr(i,0,m) {
        ii(u); ii(v);
        adj[v].push_back(u);
        ++ind[u];
    }
    stack<int> st;
    fr(i,1,n+1) {
        if (ind[i]==0) st.push(i);
    }
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (auto v : adj[u]) {
            dp[v]+=dp[u];
            if (dp[v]>=mod) dp[v]-=mod;
            if (--ind[v]==0) {
                st.push(v);
            }
        }
    }
    print(dp[1]);
}