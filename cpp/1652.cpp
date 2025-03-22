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

// 1652
int main() {
    fio;
    ii(n); ii(q);
    vector<vi> grid(n+1,vi(n+1));
    for (int i = 1; i<=n; ++i) {
        si(s);
        for (int j = 1; j<=n; ++j) {
            grid[i][j] = s[j-1]=='*';
            grid[i][j]+=grid[i-1][j];
            grid[i][j]+=grid[i][j-1];
            grid[i][j]-=grid[i-1][j-1];
        }
    }
    while (q--) {
        ii(y1); ii(x1); ii(y2); ii(x2);
        int res = grid[y2][x2];
        res-= grid[y2][x1-1];
        res-= grid[y1-1][x2];
        res+= grid[y1-1][x1-1];
        print(res);
    }
}