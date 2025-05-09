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
ll inf = 151515151515151;
ll mod = 1000000007;

class segment_tree {
    private:
    int n;
    vll a;
    public:
    segment_tree(vll arr) {
        n=1;
        while (n<arr.size()) n<<=1;
        a.assign(n<<1,inf);
        copy(arr.begin(),arr.end(),a.begin()+n);
        for (int i=n-1; i; --i) {
            a[i]=min(a[i*2],a[i*2+1]);
        }
    }

    void update(int i, ll x) {
        i+=n;
        a[i]=x;
        i>>=1;
        while (i) {
            a[i]=min(a[i*2],a[i*2+1]);
            i>>=1;
        }
    }

    ll query(int l, int r) {
        ll res = inf;
        l+=n; r+=n;
        while (l<r) {
            if (l&1) {
                res=min(res, a[l]);
                ++l;
            }
            if (r&1) {
                --r;
                res=min(res, a[r]);
            }
            l>>=1; r>>=1;
        }
        return res;
    }
};
int main() {
    ii(n); ii(q);
    vll a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    vll enumerate(n,1);
    vll tmp(n);
    partial_sum(enumerate.begin(),enumerate.end(),tmp.begin());
    transform(a.begin(),a.end(),tmp.begin(),tmp.begin(),plus<ll>());
    segment_tree forwards(tmp);
    partial_sum(enumerate.rbegin(),enumerate.rend(),tmp.rbegin());
    transform(a.begin(),a.end(),tmp.begin(),tmp.begin(),plus<ll>());
    segment_tree backwards(tmp);
    for (int i=0;i<q;++i) {
        ii(t); ii(k);
        if (t==1) {
            ii(u);
            forwards.update(k-1, u+k);
            backwards.update(k-1, u+n+1-k);
        } else {
            ll l = backwards.query(0,k)+k-1-n;
            ll r = forwards.query(k,n)-k;
            ll res = min(l, r);
            print(res);
        }
    }
}