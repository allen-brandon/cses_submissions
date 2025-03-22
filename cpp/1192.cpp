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

// 1192
int find(int a, auto& root) {
    while (root[a]!=root[root[a]]) {
        root[a]=root[root[a]];
    }
    return root[a];
}
void join(int a, int b, auto& root, auto& size) {
    a = find(a, root); b = find(b, root);
    if (a == b) return;
    if (size[b]>size[a]) {
        root[a] = b;
        size[b]+=size[a];
    } else {
        root[b] = a;
        size[a]+=size[b];
    }
}

int main() {
    fio;
    lli(n);lli(m);
    vector<vi> v(n);
    auto enc = [m](int i, int j) { return i*m+j; };
    string c;
    vi size(m*n,1);
    vi root(m*n);
    partial_sum(size.begin(),size.end()-1,root.begin()+1);
    int hashtags = 0;
    for (int i=0;i<n;++i) {
        cin >> c;
        for (int j=0;j<m;++j) {
            v[i].emplace_back(c[j]=='.');
            hashtags+=c[j]=='#';
            if (i && v[i][j]&v[i-1][j]) join(enc(i,j),enc(i-1,j),root,size);
            if (j && v[i][j]&v[i][j-1]) join(enc(i,j),enc(i,j-1),root,size);
        }
    }
    for (int i=0;i<m*n;++i) find(i,root);
    set<int> res(root.begin(),root.end());
    print(res.size()-hashtags);
}