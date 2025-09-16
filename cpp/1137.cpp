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

class SegmentTree {
    private:
    vll a;
    int n;
    public:
    SegmentTree(vll arr) {
        n = 1;
        while (n<arr.size()) n<<=1;
        a.assign(n<<1,0);
        copy(arr.begin(),arr.end(),a.begin()+n);
        for (int i=n-1; i>0; --i) {
            a[i] = a[i<<1]+a[(i<<1)+1];
        }
    }
    void update(int i, ll x) {
        i+=n;
        a[i] = x;
        i>>=1;
        while (i!=0) {
            a[i] = a[i<<1]+a[(i<<1)+1];
            i>>=1;
        }
    }
    ll query(int l, int r) {
        l+=n; r+=n;
        ll res = 0;
        int r_inc = r+1;
        while (l<r) {
            if (l&1) {
                res+=a[l];
                ++l;
            }
            if (r&1) {
                --r;
                res+=a[r];
            }
            l>>=1;
            r>>=1;
        }
        return res;
    }
    void print_array() {
        printv(a);
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
    vll vals;
    vals.reserve(n*2);
    auto assign = [](auto& assign, vll& vals, int u, int p) -> void {
        idcs[u][0] = vals.size();
        vals.push_back(a[u]);
        for (int v : adj[u]) {
            if (v==p) continue;
            assign(assign,vals,v,u);
        }
        idcs[u][1] = vals.size();
        vals.push_back(a[u]);
    };
    assign(assign, vals, 0, -1);
    SegmentTree st(vals);
    ll x = st.query(0,n);
    vll res;
    fr(i,0,q) {
        ii(t); ii(u);
        --u;
        auto [l,r] = idcs[u];
        if (t==1) {
            lli(x);
            st.update(l,x);
            st.update(r,x);
        } else {
            ll x = st.query(l,r+1) / 2;
            res.push_back(x);
        }
    }
    for (auto x : res) print(x);
}