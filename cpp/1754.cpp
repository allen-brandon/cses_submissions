//1754
using namespace std;
#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define p(_) cout << _ << '\n';
#define pv(_) for (const auto& x : _) cout << x << ' '; cout << '\n';
#define ii(_) int _; cin >> _;
#define lli(_) ll _; cin >> _;
string solve(int a, int b) {
    if ((a+b)%3!=0 || float(max(a,b))/float(min(a,b))>2) {
        return "NO";
    }
    return "YES";
}
int main() {
    fio
    ii(t);
    for (int i=0;i<t;++i) {
        ii(a);ii(b);
        p(solve(a,b));
    }
}