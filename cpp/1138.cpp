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
ll a[200001];
int tour[400002];
int idcs[200001][2];
array<vi,200001> adj;

struct BIT {
    private:
    vll arr;
    int n;
    public:
    BIT(int n) {
        this->n = n+1;
        arr.assign(n+1,0);
    }
    void update(int i, ll dx) {
        for (; i<n; i = i|(i+1)) arr[i]+=dx;
    }

    ll query(int i) {
        ll res = 0;
        for (; i>=0; i = (i&(i+1))-1) res+=arr[i];
        return res;
    }
};

int main() {
    USE_INPUT_FILE("_input.txt");
    fio;
    ii(n); ii(q);
    fill_n(adj.begin(), n+1, vi());
    fr(i,0,n) {
        lli(x);
        a[i] = x;
    }
    fr(i,0,n-1) {
        ii(u); ii(v);
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int tour_idx = 0;
    int* idx = &tour_idx;
    auto assign = [](auto& assign, int* idx, int u, int p) -> void {
        idcs[u][0] = *idx;
        ++(*idx);
        for (int v : adj[u]) {
            if (v==p) continue;
            assign(assign,idx,v,u);
        }
        idcs[u][1] = *idx;
        ++(*idx);
    };
    assign(assign, idx, 0, -1);
    BIT bit(*idx);
    fr(u,0,n) {
        auto [l,r] = idcs[u];
        bit.update(l,a[u]);
        bit.update(r+1,-a[u]);
    }
    vll res;
    fr(i,0,q) {
        ii(t); ii(u);
        --u;
        auto [l,r] = idcs[u];
        if (t==1) {
            lli(x);
            ll dx = x-a[u];
            bit.update(l,dx);
            bit.update(r+1,-dx);
            a[u] = x;
        } else {
            ll x = bit.query(l);
            res.push_back(x);
        }
    }
    for (auto x : res) print(x);
}