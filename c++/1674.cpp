using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <deque>
#include <numeric>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define ull unsigned ll
#define vll vector<ll>
#define vi vector<int>
#define counter(_) unordered_map<_,size_t>
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define print(_) cout << _ << "\n";
#define printv(_) for (const auto& x : _) cout << x << ' '; cout << '\n';
#define printum(_) cout<<"{";for (const auto& kvp:_) cout<<kvp.first<<":"<<kvp.second<<","; cout<<"}\n";
#define si(_) string _; cin >> _;
#define ii(_) int _; cin >> _;
#define lli(_) ll _; cin >> _;
ll inf = 1000000007;
ll mod = 1000000007;

// 1674
int main() {
    fio;
    ii(n);
    vi ind(n);
    vi a(n);
    for (int i=1;i<n;++i) {
        ii(x);
        a[i]=x-1;
        ++ind[x-1];
    }
    vi st;
    for (int i=0;i<n;++i) {
        if (!ind[i]) st.push_back(i);
    }
    vi res(ind);
    while (st.size()!=0) {
        int u = st[st.size()-1];
        st.pop_back();
        if (!u) continue;
        int v = a[u];
        res[v]+=res[u];
        if (!--ind[v]) st.push_back(v);
    }
    printv(res);
}