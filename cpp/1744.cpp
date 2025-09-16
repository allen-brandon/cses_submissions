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
int dp[501][501];

int main() {
    USE_INPUT_FILE("_input.txt");
    fio;
    ii(n); ii(m);
    if (n>m) swap(n,m);
    fr(i,1,n+1) {
        fr(j,1,m+1) dp[i][j] = 1000000;
    }
    fr(i,1,n+1) {
        fr(j,1,m+1) {
            if (i==j) {
                dp[i][j] = 0;
                continue;
            }
            int msf = 1000000;
            fr(k,1,i) {
                msf = min(msf, dp[k][j] + dp[i-k][j]);
            }
            fr(k,1,j) {
                msf = min(msf, dp[i][k] + dp[i][j-k]);
            }
            dp[i][j] = msf+1;
        }
    }
    // fr(i,0,n+1) {
    //     vi test(dp[i],dp[i]+m+1);
    //     printv(test);
    // }
    print(dp[n][m]);
}