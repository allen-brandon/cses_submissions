//1083
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
    // ii(n);
    int n;
    cin >> n;
    vi v;
    for (int i = 0; i < n-1; i++) {
        ii(x);
        v.push_back(x);
    }
    int x=n;
    for (int i = 0; i < n-1; i++) {
        x^=v[i];
        x^=i+1;
    }
    p(x);
}