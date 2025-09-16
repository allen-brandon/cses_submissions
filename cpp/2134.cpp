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

class SegmentTree {
    private:
    int n;
    vi a;
    public:
    SegmentTree(vi& v) {
        n = 1;
        while (n<v.size()) n<<=1;
        a.resize(n<<1);
        copy(v.begin(), v.end(), a.begin()+n);
        for (int i=n-1; i>0; --i) {
            a[i] = max(a[i*2], a[i*2+1]);
        }
    }
    
    void update(int i, int x) {
        i+=n;
        a[i] = x;
        i<<=1;
        while (i>0) {
            a[i] = max(a[i*2], a[i*2+1]);
            i<<=1;
        }
    }
    
    int query(int l, int r) {
        int res = 0;
        l+=n; r+=n;
        while (l<r) {
            if (l&1) {
                res = max(res, a[l]);
                ++l;
            }
            if (r&1) {
                --r;
                res = max(res, a[r]);
            }
            l>>=1;
            r>>=1;
        }
        return res;
    }
};
int pop[200001];
int vals[200001];
int depth[200001];
int tour[200001][2];
int anc[200001][20];
array<vi,200001> adj;

int lca(int u, int v) {
    if (depth[u]>depth[v]) swap(u,v);
    auto [l,r] = tour[v];
    if (tour[u][0] < l && tour[v][1] > r) return u;
    int x = u;
    for (int j = 19; j>=0; --j) {
        int y = anc[x][j];
        if (tour[u][0] > l || tour[v][1] < r) x = y;
    }
    return anc[x][0];
}

int main() {
    USE_INPUT_FILE("_input.txt");
    fio;
    ii(n); ii(q);
    fr(i,0,n) {
        ii(x);
        vals[i] = x;
    }
    fr(i,0,n-1) {
        ii(u); ii(v);
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int tour_idx = 0;
    stack<tuple<int,int,int,int>> st;
    st.emplace(0,0,0,0);
    while (!st.empty()) {
        auto [u,p,d,x] = st.top();
        st.pop();
        tour[u][x^1] = tour_idx++;
        if (x==0) {
            for (auto v : adj[u]) {
                if (v==p) continue;
                pop[u]+=pop[v];
            }
            continue;
        }
        depth[u] = d;
        anc[u][0] = p;
        fr(j,1,20) {
            anc[u][j] = anc[p][j>>1];
        }
        st.emplace(u,p,d,0);
        for (auto v : adj[u]) {
            if (v==p) continue;
            st.emplace(v,u,d+1,1);
        }
    }
    
    // HLDTree hld();
    // vi res;
    // fr(i,0,q) {
    //     ii(t);
    //     if (t==1) {
    //         ii(u); ii(x);
    //         --u;
    //         hld.update(u,x);
    //     } else {
    //         ii(u); ii(v);
    //         --u; --v;
    //         res.push_back(hld.query(u,v));
    //     }
    // }
    // printv(res);
}