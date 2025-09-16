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
array<pair<int,int>,8> didj = {{{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}}};
array<string,2> ny = {"No","Yes"};
ll inf = 151515151515151;
ll mod = 998244353;

int main() {
    USE_INPUT_FILE("_input.txt");
    fio;
    ii(n);
    vector<vi> res(n);
    fill_n(res.begin(), n, vi(n,-1));
    res[0][0] = 0;
    vi cur(1,0);
    while (!cur.empty()) {
        vi tmp;
        for (auto x : cur) {
            int i=x/n, j=x%n;
            for (auto [di,dj] : didj) {
                int i1=i+di, j1=j+dj;
                if (i1>=0 && j1>=0 && i1<n && j1<n && res[i1][j1]==-1) {
                    res[i1][j1] = res[i][j]+1;
                    tmp.push_back(i1*n+j1);
                }
            }
        }
        cur.swap(tmp);
    }
    for (auto& row : res) {
        printv(row);
    }
}