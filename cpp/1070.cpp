//1070
using namespace std;
#include <iostream>
#include <vector>
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define p(_) cout << _ << '\n';
#define pa(_) for (const auto& x : _) cout << x << ' '; cout << '\n';
#define ii(_) int _; cin >> _;
#define lli ll _; cin >> _;
int main() {
    fio;
    ii(n);
    if (n<4) {
        string ns = "NO SOLUTION";
        if (n==1) {p(1);}
        else p(ns);
        return 0;
    }
    vi v;
    for (int i=2;i<=n;i+=2) v.push_back(i);
    for (int i=1;i<=n;i+=2) v.push_back(i);
    pa(v);
}