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

//1647
class sparse_table {
    private:
    vector<vi> table;
    public:
    sparse_table(const vi& a) {
        int n = 2;
        vi row(a);
        table.push_back(row);
        while (n<=a.size()) {
            vi tmp(a.size()+1-n);
            for (int i=0;i<tmp.size();++i) tmp[i] = min(row[i],row[i+n/2]);
            row = tmp;
            table.push_back(row);
            n<<=1;
        }
    }
    
    int query(int l, int r) {
        int n = 1, i=0;
        while (n<=r-l) {
            n<<=1;
            ++i;
        }
        n>>=1;
        --i;
        return min(table[i][l],table[i][r-n]);
    }
};
// 1647
int main() {
    fio;
    ii(n); ii(q);
    vi a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    sparse_table st(a);
    for (int i=0;i<q;++i) {
        ii(l); ii(r);
        print(st.query(l-1,r));
    }
}