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

class fenwick_tree {
    private:
    int n;
    vll a;
    public:
    
    fenwick_tree(const vll& arr): a(arr) {
        n = arr.size();
        if (n>1) a[1]+=a[0];
        for (int i=1; i<n;++i) {
            a[i]-=arr[i-1];
            if ((i|(i+1))<n) a[i|(i+1)]+=a[i];
        }
    }
    
    void update(int l, int r, ll x) {
        while (l<n) {
            a[l]+=x;
            l|=l+1;
        }
        while (r<n) {
            a[r]-=x;
            r|=r+1;
        }
    }
    
    ll query(int i) {
        ll res = 0;
        while (i) {
            res+=a[i-1];
            i&=i-1;
        }
        return res;
    }
    
};

// 1651
int main() {
    lli(n); lli(q);
    vll a(n);
    for (ll i=0;i<n;++i) cin >> a[i];
    fenwick_tree st(a);
    for (ll i=0;i<q;++i) {
        lli(t);
        if (t==1) {
            ii(l); ii(r); lli(x);
            st.update(l-1,r,x);
        } else {
            ii(idx);
            print(st.query(idx));
        }
    }
}