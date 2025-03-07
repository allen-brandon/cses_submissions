//1618
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

int main() {
    fio
    ii(n);
    ll x = 5;
    int res = 0;
    while (x <= n) {
        res+=(n/x);
        x*=5;
    }
    p(res);
}