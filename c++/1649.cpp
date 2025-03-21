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

class segment_tree {
    private:
    int n;
    vll a;
    public:
    segment_tree(vll& arr) {
        n=1;
        while (n<arr.size()) n<<=1;
        a.assign(n<<1, inf);
        copy(arr.begin(), arr.end(), a.begin()+n);
        for (int i = n-1; i; --i) {
            a[i] = min(a[i*2], a[i*2+1]);
        }
    }
    
    void update(int i, int x) {
        i+=n;
        a[i] = x;
        while (i) {
            i>>=1;
            a[i] = min(a[i*2], a[i*2+1]);
        }
    }
    
    ll query(int l, int r) {
        l+=n; r+=n;
        ll res = inf;
        while (l<r) {
            if (l&1) {
                res = min(res, a[l]);
                l+=1;
            }
            if (r&1) {
                r-=1;
                res = min(res, a[r]);
            }
            l>>=1;
            r>>=1;
        }
        return res;
    }
};

// 1649
int main() {
    lli(n); lli(q);
    vll a(n);
    for (ll i=0;i<n;++i) cin >> a[i];
    segment_tree st(a);
    for (ll i=0;i<q;++i) {
        lli(t); lli(l); lli(r);
        if (t==1) {
            st.update(l-1,r);
        } else {
            print(st.query(l-1,r));
        }
    }
}