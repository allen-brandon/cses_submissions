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

int find(int a, auto& root) {
    while (root[a] != root[root[a]]) {
        root[a] = root[root[a]];
    }
    return root[a];
}

int join(int a, int b, auto& root, auto& size) {
    a = find(a, root); b = find(b, root);
    if (a==b) return 0;
    if (size[b]>size[a]) {
        root[a] = b;
        size[b]+=size[a];
    } else {
        root[b] = a;
        size[a]+=size[b];
    }
    return 1;
}

// 1666
int main() {
    ii(n); ii(m);
    vector<pair<int,int>> edges;
    edges.reserve(m);
    vi size(n+1,1);
    vi root(n+1);
    partial_sum(size.begin(),size.end()-1,root.begin()+1);
    for (int i = 0; i<m; ++i) {
        ii(a);ii(b);
        edges.emplace_back(a,b);
        join(a,b,root,size);
    }
    vector<vi> res;
    for (int i = 1; i < n; ++i) {
        if (join(i,i+1,root,size)) {
            res.push_back({i,i+1});
        }
    }
    print(res.size());
    for (const auto& row : res) {
        printv(row);
    }
}