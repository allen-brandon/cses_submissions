//1622
using namespace std;
#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define counter(_) unordered_map<_,size_t>
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define p(_) cout << _ << '\n';
#define pv(_) for (const auto& x : _) cout << x << ' '; cout << '\n';
#define pum(_) cout<<"{";for (const auto& kvp:_) cout<<kvp.first<<":"<<kvp.second<<","; cout<<"}\n";
#define si(_) string _; cin >> _;
#define ii(_) int _; cin >> _;
#define lli(_) ll _; cin >> _;
int inf = 1000000007;

int main() {
    fio
    si(s);
    sort(s.begin(),s.end());
    string t = s;
    int n = s.size();
    string prev = "";
    vector<string> v = {s};
    next_permutation(t.begin(),t.end());
    while (t!=s) {
        if (prev != t) v.push_back(t);
        prev = t;
        next_permutation(t.begin(),t.end());
    }
    p(v.size());
    for (const auto& x : v) p(x);
}