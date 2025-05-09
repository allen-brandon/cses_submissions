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
    vll pend;

    public:

    segment_tree(vll arr) {
        n = 1;
        while (n<arr.size()) n<<=1;
        a.assign(n<<1, -inf);
        copy(arr.begin(), arr.end(), a.begin()+n);
        for (int i=n-1; i; --i) {
            a[i] = max(a[i*2],a[i*2+1]);
        }
        pend.assign(n<<1, 0);
    }

    void prop(int i) {
        if (!pend[i] || !i) return;
        pend[i*2]+=pend[i];
        pend[i*2+1]+=pend[i];
        a[i]+=pend[i];
        // a[i*2]+=pend[i];
        // a[i*2+1]+=pend[i];
        pend[i]=0;
    }

    void update(int l, int r, ll x) {
        l+=n; r+=n;
        int lb=l, rb=r, r_inclusive=r-1;
        for (int i=32-__builtin_clz(l);i;--i) {
            prop(lb>>i);
            prop(r_inclusive>>i);
        }
        while (lb<rb) {
            if (lb&1) {
                // a[lb]+=x;
                pend[lb]+=x;
                ++lb;
            }
            if (rb&1) {
                --rb;
                // a[rb]+=x;
                pend[rb]+=x;
            }
            lb>>=1;
            rb>>=1;
        }
        lb = l>>1;
        rb = r_inclusive>>1;
        while (lb) {
            // a[lb] = max(a[lb*2],a[lb*2+1]);
            // a[rb] = max(a[rb*2],a[rb*2+1]);
            a[lb] = max(a[lb*2]+pend[lb*2],a[lb*2+1]+pend[lb*2+1]);
            a[rb] = max(a[rb*2]+pend[rb*2],a[rb*2+1]+pend[rb*2+1]);
            lb>>=1;
            rb>>=1;
        }
    }

    ll query(int l, int r) {
        l+=n; r+=n;
        int lb=l, rb=r, r_inclusive=r-1;
        for (int i=32-__builtin_clz(l);i;--i) {
            prop(l>>i);
            prop(r_inclusive>>i);
        }
        ll res = -inf;
        while (lb<rb) {
            if (lb&1) {
                res=max(res,a[lb]+pend[lb]);
                ++lb;
            }
            if (rb&1) {
                --rb;
                res=max(res,a[rb]+pend[rb]);
            }
            lb>>=1;
            rb>>=1;
        }
        return res;
    }

    ll query(int i) {
        i+=n;
        for (int j=32-__builtin_clz(i);j;--j) prop(i>>j);
        return a[i]+pend[i];
    }

};

int main() {
    ii(n); ii(q);
    vll a(n+1);
    for (int i=1;i<=n;++i) cin >> a[i];
    vll pref; pref.reserve(n+1);
    partial_sum(a.begin(),a.end(),back_inserter(pref));
    segment_tree st(pref);
    for (int i=0;i<q;++i) {
        ii(t);
        if (t==1) {
            ii(u); lli(k);
            ll du = k-a[u];
            st.update(u,n+1,du);
            a[u]=k;
        } else {
            ii(l); ii(r);
            ll res = max(0ll,st.query(l,r+1)-st.query(l-1));
            print(res);
        }
    }
}