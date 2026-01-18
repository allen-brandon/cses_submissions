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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order(), order_of_key()
typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
#define vll vector<ll>
#define vi vector<int>
#define counter(_) unordered_map<_,size_t>
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
ll mod = 1000000007;
vi adj[200001];
int id[200001];
int ind[200001];

int main() {
    USE_INPUT_FILE("_input.txt");
    fio;
    ii(n); ii(m);
    fill_n(adj,n, vi());
    fill_n(ind,n,0);
    fill_n(id,n,0);
    set<pair<int,int>> test;
    fr(i,0,m) {
        ii(u); ii(v);
        // print(u << " " << v);
        test.emplace(u,v);
        u--; v--;
        ind[u]++;
        ind[v]--;
        adj[u].push_back(v);
    }
    if (ind[0]!=1 || ind[n-1]!=-1) {
        print("IMPOSSIBLE");
        return 0;
    }
    fr(i,1,n-1) {
        if (ind[i]!=0) {
            print("IMPOSSIBLE");
            return 0;
        }
    }
    fr(u,0,n) {
        sort(adj[u].begin(),adj[u].end(),[u](int v1, int v2) {
            return adj[v1].size()-id[v1]>adj[v2].size()-id[v2];
        });
    }
    vi res;
    res.reserve(m+1);
    stack<int> st;
    st.push(0);
    while (!st.empty()) {
        int u = st.top();
        if (id[u]==adj[u].size()) {
            res.push_back(u);
            st.pop();
        } else {
            int v = adj[u][id[u]++];
            st.push(v);
        }
    }
    if (res.size()!=m+1) {
        print("IMPOSSIBLE")
        return 0;
    }
    fr(i,0,m+1) {
        res[i]++;
    }
    reverse(res.begin(),res.end());
    printv(res);
}