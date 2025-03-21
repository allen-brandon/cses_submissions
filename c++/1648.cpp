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
#define ll long long
#define ull unsigned ll
#define vll vector<ll>
#define vi vector<int>
#define counter(_) unordered_map<_,size_t>
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define print(_) cout << _ << "\n";
#define printv(_) for (const auto& x : _) cout << x << ' '; cout << '\n';
#define printum(_) cout<<"{";for (const auto& kvp:_) cout<<kvp.first<<":"<<kvp.second<<","; cout<<"}\n";
#define si(_) string _; cin >> _;
#define ii(_) int _; cin >> _;
#define lli(_) ll _; cin >> _;
ll inf = 1000000007;
ll mod = 1000000007;


// 1648
class fenwick_tree {
    private:
    vll arr;
    public:
    fenwick_tree(const vll& a): arr(a) {
        ll n = arr.size();
        for (ll i=0; i<n; ++i) {
            if ((i|(i+1))<n) arr[i|(i+1)]+=arr[i];
        }
    }
    
    void update(ll i, ll x) {
        ll old_val = query(i,i+1);
        ll dx = x-old_val;
        while (i<arr.size()) {
            arr[i]+=dx;
            i |= i+1;
        }
    }
    
    ll query(ll l, ll r) {
        ll res = 0;
        while (r) {
            res+=arr[r-1];
            r&=r-1;
        }
        while (l) {
            res-=arr[l-1];
            l&=l-1;
        }
        return res;
    }
};

int main() {
    lli(n); lli(q);
    vll a(n);
    for (ll i=0;i<n;++i) cin >> a[i];
    fenwick_tree ft(a);
    for (ll i=0;i<q;++i) {
        lli(t); lli(l); lli(r);
        if (t==1) {
            ft.update(l-1,r);
        } else {
            print(ft.query(l-1,r));
        }
    }
}