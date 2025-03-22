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

//1667
int main() {
    ii(n); ii(m);
    vector<vi> adj(n+1);
    vi seen(n+1);
    for (int i=0;i<m;++i) {
        ii(a); ii(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    deque<int> q = {1};
    while (q.size() && !seen[n]) {
        int i = q[0];
        q.pop_front();
        for (int j : adj[i]) {
            if (seen[j]) continue;
            seen[j] = i;
            q.push_back(j);
        }
    }
    if (!seen[n]) {
        print("IMPOSSIBLE")
        return 0;
    }
    vi res;
    int i = n;
    while (i>1) {
        res.push_back(i);
        i = seen[i];
    }
    res.push_back(1);
    print(res.size());
    printv(vi(res.rbegin(),res.rend()));
}