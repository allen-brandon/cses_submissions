//2205
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

vector<string> construct(int n) {
    if (n == 1) return vector<string> {"0","1"};
    vector<string> half = construct(n-1);
    vector<string> res;
    for (string s : half) {
        res.push_back("0"+s);
    }
    reverse(half.begin(),half.end());
    for (string s : half) {
        res.push_back("1"+s);
    }
    return res;
}

int main() {
    ii(n);
    vector<string> res = construct(n);
    for (string s : res) p(s);
}