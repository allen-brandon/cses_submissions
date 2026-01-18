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
vi adj[501];
int l[501]; //level
int p[501]; //parent
int cap[501][501]; //capacity

int main() {
    USE_INPUT_FILE("_input.txt");
    fio;
    ii(n); ii(m);
    fr(i,0,m) {
        ii(u); ii(v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] = 1;
        cap[v][u] = 1;
    }
    vi cur, tmp;
    cur.reserve(n);
    tmp.reserve(n);
    fr(step,0,mod) {
        fill_n(l,n+1,-1);
        l[0] = 0;
        cur.push_back(0);
        while (!cur.empty()) {
            for (auto u : cur) {
                for (auto v : adj[u]) {
                    if (l[v]!=-1 || cap[u][v]==0) continue;
                    l[v] = l[u]+1;
                    tmp.push_back(v);
                }
            }
            cur.swap(tmp);
            tmp.clear();
        }
        if (l[n-1]==-1) break;
        bool found = true;
        while (found) {
            found = false;
            fill_n(p,n,-1);
            stack<pair<int,int>> st;
            st.emplace(0,1);
            while (!st.empty() && !found) {
                auto [u,d] = st.top();
                st.pop();
                if (d==0) continue;
                st.emplace(u,0);
                for (int v : adj[u]) {
                    if (l[v]!=l[u]+1 || p[v]!=-1 || cap[u][v]==0) continue;
                    p[v] = u;
                    if (v==n-1) {
                        found = true;
                        break;
                    }
                    st.emplace(v,1);
                }
            }
            if (found) {
                int u = n-1, msf = mod;
                while (u!=0) {
                    int v = p[u];
                    msf = min(msf, cap[v][u]);
                    u = v;
                }
                u = n-1;
                while (u!=0) {
                    int v = p[u];
                    cap[v][u] -= msf;
                    cap[u][v] += msf;
                    u = v;
                }
            }
        }
    }
    fill_n(p,n,0); // S or V/S
    vector<pair<int,int>> res;
    stack<int> st;
    st.push(0);
    p[0] = 1;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int v : adj[u]) {
            if (p[v]==1 || cap[u][v]==0) continue;
            p[v] = 1;
            st.push(v);
        }
    }
    st.push(0);
    p[0]++;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int v : adj[u]) {
            if (p[v]==1) {
                st.push(v);
                p[v]++;
            } else if (p[v]==0) {
                res.emplace_back(u+1,v+1);
            }
        }
    }
    print(res.size());
    for (auto [u,v] : res) {
        print(u << " " << v);
    }
}