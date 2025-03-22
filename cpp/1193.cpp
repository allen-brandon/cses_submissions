using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <deque>
#include <numeric>
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

vector<pair<int,int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
string URDL = "URDL";

// 1193
int main() {
    fio;
    ii(n);ii(m);
    vector<vi> v(n);
    vi seen(m*n,-1);
    auto enc = [m](int i, int j) { return i*m+j; };
    auto dec = [m](int idx) -> pair<int,int> { return {idx/m, idx%m}; };
    int start, end;
    int idx, i, j;
    string c;
    for (i=0;i<n;++i) {
        cin >> c;
        for (j=0;j<m;++j) {
            v[i].emplace_back(c[j]!='#');
            if (c[j] == 'A') start=enc(i,j);
            if (c[j] == 'B') end=enc(i,j);
        }
    }
    deque<int> q = {start};
    while (q.size() && seen[end]==-1) {
        idx = q[0];
        q.pop_front();
        auto [i, j] = dec(idx);
        for (int d = 0; d<4; ++d) {
            auto [di, dj] = directions[d];
            int x=i+di, y=j+dj;
            int new_idx = enc(x,y);
            if (x<0 || y<0 || x==n || y==m || !v[x][y] || seen[new_idx]!=-1) continue;
            seen[new_idx]=d;
            q.push_back(new_idx);
        }
    }
    if (seen[end]==-1) {
        print("NO");
        return 0;
    }
    print("YES");
    vector<char> path;
    i = end/m; j = end%m; idx = end;
    while (idx != start) {
        path.push_back(URDL[seen[idx]]);
        auto [di,dj] = directions[seen[idx]];
        i-=di;
        j-=dj;
        idx = enc(i,j);
    }
    print(path.size());
    print(string(path.rbegin(),path.rend()));
}