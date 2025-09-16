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
int a[200001];
int res[200001];
array<vi,200001> adj;
struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
array<gp_hash_table<int,null_type,chash>,200001> sets;

int main() {
    USE_INPUT_FILE("_input.txt");
    fio;
    ii(n);
    fr(i,0,n) {
        ii(x);
        a[i] = x;
    }
    fill_n(adj.begin(), n+1, vi());
    fr(i,0,n-1) {
        ii(u); ii(v);
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    stack<tuple<int,int,int>> st;
    st.emplace(0,0,1);
    while (st.size()!=0) {
        auto [u,p,d] = st.top();
        st.pop();
        if (d==0) {
            for (auto v : adj[u]) {
                if (v==p) continue;
                if (sets[v].size()>sets[u].size()) {
                    sets[u].swap(sets[v]);
                }
                for (auto x : sets[v]) sets[u].insert(x);
            }
            sets[u].insert(a[u]);
            res[u] = sets[u].size();
            continue;
        }
        st.emplace(u,p,0);
        for (auto v : adj[u]) {
            if (v==p) continue;
            st.emplace(v,u,1);
        }
    }
    fr(i,0,n) {
        cout << res[i] << " ";
    }
    cout << "\n";
}