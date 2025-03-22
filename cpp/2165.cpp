//2165
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
    ii(n);
    int a = 1;
    int b = 2+(n&1);
    int c = 3-(n&1);
    vector<vi> stacks = {{inf},{inf},{inf},{inf}};
    for (int i=n;i>0;--i) stacks[1].push_back(i);
    vector<vi> res;
    p((1<<n)-1);
    vector<vi> steps = {{a,b},{a,c},{b,c}};
    vi step;
    for (int i=0;i<(1<<n)-1;++i) {
        step = steps[i%3];
        int t1 = step[0];
        int t2 = step[1];
        if (stacks[t2].back() < stacks[t1].back()) {
            stacks[t1].push_back(stacks[t2].back());
            stacks[t2].pop_back();
            res.push_back({t2,t1});
        } else {
            stacks[t2].push_back(stacks[t1].back());
            stacks[t1].pop_back();
            res.push_back({t1,t2});
        }
    }
    for (const auto& line : res) {
        pv(line);
    }
}