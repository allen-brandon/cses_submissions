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

// 1143
class segment_tree {
    private:
    vi arr;
    int n;
    public:
    segment_tree(const vi& a) {
        n = 1;
        while (n<a.size()) n<<=1;
        arr = vi(n<<1,0);
        copy(a.begin(), a.end(), arr.begin()+n);
        for (int i = n-1; i; --i) arr[i] = max(arr[i<<1], arr[(i<<1)+1]);
    }
    
    void update(int i, int x) {
        i+=n;
        arr[i]+=x;
        i>>=1;
        while (i) {
            arr[i] = max(arr[i<<1], arr[(i<<1)+1]);
            i>>=1;
        }
    }
    
    int query(int l, int r) {
        int res = 0;
        l+=n; r+=n;
        while (l<r) {
            if (l&1) {
                res = max(res, arr[l]);
                ++l;
            }
            if (r&1) {
                --r;
                res = max(res, arr[r]);
            }
            l>>=1;
            r>>=1;
        }
        return res;
    }
    
    int lower_bound(int x) {
        int i = 1;
        if (arr[1]<x) return -1;
        while (i<n) {
            i<<=1;
            if (arr[i]<x) ++i;
        }
        return i-n;
    }
};

int main() {
    ii(n); ii(m);
    vi a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    vi b(m);
    for (int i=0;i<m;++i) cin >> b[i];
    segment_tree st(a);
    vi res(m,0);
    for (int i=0;i<m;++i) {
        int j = st.lower_bound(b[i]);
        if (j!=-1) {
            st.update(j,-b[i]);
            res[i]=j+1;
        }
    }
    printv(res);
}