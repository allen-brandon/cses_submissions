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
// struct chash {
//     static uint64_t splitmix64(uint64_t x) {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }
//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM =
//             chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };
ll inf = 151515151515151;
ll mod = 998244353;
int first[200001];
int depth[200001];
int tour[400002];
int pop[200001];
int res[200001];
bitset<200001> removed;
array<vi,200001> adj;
// array<map<int,ll>,200001> dists;
// array<gp_hash_table<int,ll,chash>,200001> dists;
// array<gp_hash_table<int,ll,chash>,200001> neg;
array<vll,200001> dists; 
array<vll,200001> neg; 
array<vector<pair<int,int>>,200001> anc;


class SparseTable {
    private:
    vector<vi> table;

    public:
    SparseTable(int n) {
        vi cur; cur.reserve(n);
        fr(i,0,n) cur.push_back(tour[i]);
        table.push_back(cur);
        int j = 1;
        while ((1<<j)<=n) {
            vi cur; cur.reserve(n+1-(1<<j));
            fr(i,0,n+1-(1<<j)) {
                cur.push_back(min(table.back()[i], table.back()[i+(1<<(j-1))]));
            }
            table.push_back(cur);
            ++j;
        }
    }
    int query(int l, int r) {
        int m = r+1-l;
        int j = 0;
        while ((1<<j) <= m) ++j;
        --j;
        return min(table[j][l], table[j][r+1-(1<<j)]);
    }
    int dist(int u, int v) {
        int lb = first[u], rb = first[v];
        if (lb>rb) swap(lb, rb);
        int lca_d = query(lb, rb);
        return depth[u]+depth[v]-lca_d*2;

    }
};

class CentroidTree {
    private:
    SparseTable& table;
    int n;
    public:
    CentroidTree(int n, SparseTable& table) : table(table), n(n) {
        fill_n(dists.begin(), n+1, vll());
        fill_n(neg.begin(), n+1, vll());
        fill_n(anc.begin(), n+1, vector<pair<int,int>>());
        fr(i,0,n) removed[i] = 0;
        stack<tuple<int,int,int>> st;
        st.emplace(0,n,-1);
        while (!st.empty()) {
            auto [u,n,c] = st.top();
            st.pop();
            bool centroid = true;
            for (auto v : adj[u]) {
                if (removed[v]) continue;
                int v_n = pop[v];
                if (v_n*2>n) {
                    st.emplace(v,n,c);
                    pop[u] = n-v_n;
                    centroid = false;
                    break;
                }
            }
            if (centroid) {
                dists[u].push_back(1);
                removed[u] = 1;
                if (c!=-1) {
                    int d = table.dist(u,c);
                    anc[u].emplace_back(c,d);
                    if (dists[c].size()<=d) {
                        dists[c].resize(d+1);
                    }
                    ++dists[c][d];
                    if (neg[u].size()<=d) {
                        neg[u].resize(d+1);
                    }
                    ++neg[u][d];
                    int prev = c;
                    for (auto [c2, _] : anc[c]) {
                        int d2 = table.dist(u,c2);
                        anc[u].emplace_back(c2,d2);
                        if (dists[c2].size()<=d2) {
                            dists[c2].resize(d2+1);
                        }
                        ++dists[c2][d2];
                        if (neg[prev].size()<=d2) {
                            neg[prev].resize(d2+1);
                        }
                        ++neg[prev][d2];
                        prev = c2;
                    }
                }
                for (auto v : adj[u]) {
                    if (removed[v]) continue;
                    st.emplace(v,pop[v],u);
                }
            }
        }
    }
    ll query(int k) {
        ll res = 0;
        fr(u,0,n) {
            res += dists[u].size()>k?  dists[u][k] : 0;
            int prev = u;
            for (auto [c,d] : anc[u]) {
                if (k-d<0) {
                    prev = c;
                    continue;
                }
                ll inc = dists[c].size() > (k-d) ? dists[c][k-d] : 0;
                ll dec = neg[prev].size() > (k-d)? neg[prev][k-d] : 0;
                res += inc - dec;
                prev = c;
            }
        }
        return res;
    }
};

int main() {
    USE_INPUT_FILE("_input.txt");
    fio;
    ii(n); ii(k);
    fr(i,0,n-1) {
        ii(u); ii(v);
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int tour_idx = 0;
    stack<tuple<int,int,int,int>> st;
    st.emplace(0,-1,0,1);
    while (!st.empty()) {
        auto [u,p,d,x] = st.top();
        st.pop();
        if (x==0) {
            tour[tour_idx++] = d;
            pop[u]+=pop[p];
            continue;
        }
        pop[u] = 1;
        depth[u] = d;
        first[u] = tour_idx;
        tour[tour_idx++] = d;
        for (auto v : adj[u]) {
            if (v==p) continue;
            st.emplace(u,v,d,0);
            st.emplace(v,u,d+1,1);
        }
    }
    SparseTable table(tour_idx);
    CentroidTree ct(n, table);
    ll res = ct.query(k)>>1;
    print(res);
}