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
ll mod = 998244353;

int main() {
    USE_INPUT_FILE("_input.txt");
    fio;
    ii(testcases);
    fr(t,0,testcases) {
        ii(n); ii(a); ii(b);
        if (a==0 && b==0) {
            print(ny[1]);
            vi v1(n);
            vi v2(n);
            iota(v1.begin(),v1.end(),1);
            iota(v2.begin(),v2.end(),1);
            printv(v1);
            printv(v2);
            continue;
        }
        if (a==0 || b==0) {
            print(ny[0]);
            continue;
        }
        if (a+b>n) {
            print(ny[0]);
            continue;    
        }
        print(ny[1]);
        int draw = n-(a+b);
        vi v1(n);
        vi v2(n);
        iota(v2.begin(),v2.end(),1);
        fr(i,0,draw) {
            v1[i] = i+1;
        }
        fr(i,draw,draw+b) {
            v1[i+a] = i+1;
        }
        fr(i,draw,draw+a) {
            v1[i] = i+b+1;
        }
        printv(v1);
        printv(v2);
    }
}