//1755
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

int main() {
    si(s);
    counter(char) freq;
    for (char c : s) {
        ++freq[c];
    }
    vector<string> half;
    string center;
    for (const auto& kvp : freq) {
        auto& c = kvp.first;
        auto& f = kvp.second;
        half.emplace_back(f/2,c);
        if (f&1) {
            if (center.size()) {
                p("NO SOLUTION");
                return 0;
            }
            center=c;
        }
    }
    vector<string> res;
    res.insert(res.end(),half.begin(),half.end());
    res.push_back(center);
    reverse(half.begin(),half.end());
    res.insert(res.end(),half.begin(),half.end());
    for (string c : res) cout << c;
    cout << "\n";
}