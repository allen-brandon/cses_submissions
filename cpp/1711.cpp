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
vi adj1[501];
int p[501];
int l[501];
int cap[501][501];

int main() {
    USE_INPUT_FILE("_input.txt");
    fio;
    ii(n); ii(m);
    fr(i,0,n) {
        adj[i].clear();
        adj1[i].clear();
        fill_n(cap[i],n,0);
    }
    fr(i,0,m) {
        ii(u); ii(v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        adj1[u].push_back(v);
        cap[u][v]++;
    }
    vi cur, tmp;
    cur.reserve(n);
    tmp.reserve(n);
    fr(step,0,mod) {
        fill_n(l,n,-1);
        l[0] = 0;
        cur.push_back(0);
        while (!cur.empty()) {
            tmp.clear();
            for (int u : cur) {
                for (int v : adj[u]) {
                    if (l[v]!=-1 || cap[u][v]==0) continue;
                    l[v] = l[u]+1;
                    tmp.push_back(v);
                }
            }
            cur.swap(tmp);
        }
        if (l[n-1]==-1) break;
        bool found = true;
        while (found) {
            found = false;
            stack<int> st;
            st.push(0);
            fill_n(p,n,-1);
            while (!st.empty() && p[n-1]==-1) {
                int u = st.top();
                st.pop();
                for (int v : adj[u]) {
                    if (l[v]!=l[u]+1 || cap[u][v]==0 || p[v]!=-1) continue;
                    p[v] = u;
                    if (v==n-1) {
                        found = true;
                        break;
                    }
                    st.push(v);
                }
            }
            if (found) {
                int u = n-1;
                while (u!=0) {
                    int v = p[u];
                    cap[v][u]--;
                    cap[u][v]++;
                    u = v;
                }
            }
        }
    }
    vector<vi> res;
    bool blocking = true;
    while (blocking) {
        blocking = false;
        vi cur = {0};
        bool found = true;
        while (found) {
            found = false;
            int u = cur.back();
            for (int v : adj1[u]) {
                if (cap[u][v]==0) {
                    cap[u][v]++;
                    cur.push_back(v);
                    if (v==n-1) blocking = true;
                    found = true;
                    break;
                }
            }
        }
        if (blocking) {
            fr(i,0,cur.size()) cur[i]++;
            res.push_back(cur);
        }
    }
    print(res.size());
    for (vi& row : res) {
        print(row.size());
        printv(row);
    }
}