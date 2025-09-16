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

class MinTree {
    private:
    vi a;
    vi p;
    int n;
    public:
    MinTree(vll arr) {
        n = 1;
        while (n<arr.size()) n<<=1;
        a.assign(n<<1,inf);
        p.assign(n<<1,0);
        copy(arr.begin(),arr.end(),a.begin()+n);
        for (int i=n-1; i>0; --i) {
            a[i] = min(a[(i<<1)],a[(i<<1)|1]);
        }
    }
    void prop(int i) {
        if (p[i]==0) return;
        p[i*2]+=p[i];
        p[i*2+1]+=p[i];
        a[i]+=p[i];
        p[i] = 0;
    }
    void update(int l, int r, ll x) {
        l+=n; r+=n;
        int r_inc = r+1;
        for (int i = 32-__builtin_clz(l); i!=0; --i) {
            prop(l>>i);
            prop(r_inc>>i);
        }
        int lb=l, rb=r;
        while (lb<rb) {
            if (lb&1) {
                p[lb]+=x;
                lb+=1;
            }
            if (rb&1) {
                rb-=1;
                p[r]+=x;
            }
            lb>>=1;
            rb>>=1;
        }
        int lb=l>>1, rb=r_inc>>1;
        while (lb!=0) {
            a[lb] = min(a[lb*2]+p[lb*2],a[lb*2+1]+p[lb*2+1]);
            a[rb] = min(a[rb*2]+p[rb*2],a[rb*2+1]+p[rb*2+1]);
            lb>>=1;
            rb>>=1;
        }
    }
    //min of all elements up to i
    ll query(int i) { 
        i+=n;
        for (int j=32-__builtin_clz(i);j!=0;--j) prop(i>>j);
        return a[i]+p[i];
    }
};
class SegmentTree {
    private:
    vll a; //values
    vll pmin;
    vll lmin;
    vll p;
    int n;
    public:
    SegmentTree(vll arr) {
        n = 1;
        while (n<arr.size()) n<<=1;
        a.assign(n<<1,-inf);
        pmin.assign(n<<1,inf);
        lmin.assign(n<<1,inf);
        p.assign(n<<1,0);
        copy(arr.begin(),arr.end(),lmin.begin()+n);
        for (int i=n-1; i>0; --i) {
            lmin[i] = lmin[(i<<1)]+lmin[(i<<1)|1];
        }
        copy(arr.begin(),arr.end(),pmin.begin()+n);
        partial_sum(pmin.begin()+n, pmin.end(),pmin.begin()+n, [](ll& a, ll& b) { return min(a,b); });
        // fr(i,)
    }
    void prop(int i) {
        if (p[i]==0) return;
        p[i*2]+=p[i];
        p[i*2+1]+=p[i];
        a[i]+=p[i];
        p[i] = 0;
    }

    void update(int l, int r, ll x) {
        l+=n; r+=n;
        int r_inc = r+1;
        for (int i = 32-__builtin_clz(l); i!=0; --i) {
            prop(l>>i);
            prop(r_inc>>i);
        }
        int lb=l, rb=r;
        while (lb<rb) {
            if (lb&1) {
                p[lb]+=x;
                lb+=1;
            }
            if (rb&1) {
                rb-=1;
                p[r]+=x;
            }
            lb>>=1;
            rb>>=1;
        }
        int lb=l>>1, rb=r_inc>>1;
        while (lb!=0) {
            a[lb] = min(a[lb*2]+p[lb*2],a[lb*2+1]+p[lb*2+1]);
            a[rb] = min(a[rb*2]+p[rb*2],a[rb*2+1]+p[rb*2+1]);
            lb>>=1;
            rb>>=1;
        }
    }
    //min of all elements up to i
    ll query(int i) { 
        i+=n;
        for (int j=32-__builtin_clz(i);j!=0;--j) prop(i>>j);
        return a[i]+p[i];
    }
};

int main() {
    USE_INPUT_FILE("_input.txt");
    fio;
    
}