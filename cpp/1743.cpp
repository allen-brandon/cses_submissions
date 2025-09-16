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
int a[26];

int main() {
    USE_INPUT_FILE("_input.txt");
    fio;
    si(s);
    int n = s.size();
    set<pair<int,int>> st1;
    set<pair<int,int>> st2;
    for (auto x : s) {
        ++a[x-'A'];
    }
    fr(x,0,26) {
        if (a[x]!=0) {
            st1.emplace(a[x],x);
            st2.emplace(x,a[x]);
        }
    }
    auto [max_count,max_char] = *prev(st1.end());
    if (max_count>(n-max_count)+1) {
        print(-1);
        exit(0);
    }
    vi v;
    v.reserve(n);
    while (n!=0) {
        auto [max_count,max_char] = *prev(st1.end());
        if (max_count==(n-max_count)+1) {
            st1.erase(make_pair(max_count,max_char));
            st2.erase(make_pair(max_char,max_count));
            if (max_count>1) {
                st1.emplace(max_count-1,max_char);
                st2.emplace(max_char,max_count-1);
            }
            v.push_back(max_char);
        } else {
            auto [min_char, min_count] = *st2.begin();
            if (!v.empty() && v.back()==min_char) {
                auto [min_char1, min_count1] = *next(st2.begin());
                min_char = min_char1;
                min_count = min_count1;
            }
            st2.erase(make_pair(min_char,min_count));
            st1.erase(make_pair(min_count,min_char));
            if (min_count>1) {
                st2.emplace(min_char,min_count-1);
                st1.emplace(min_count-1,min_char);
            }
            v.push_back(min_char);
        }
        --n;
    }
    vector<char> res;
    res.reserve(v.size());
    fr(i,0,v.size()) {
        res.push_back(char(v[i]+65));
    }
    string s_res(res.begin(),res.end());
    print(s_res);
}