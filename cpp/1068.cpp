//1068
#define ll long long
#include <iostream>
#include <vector>
int main() {
    ll n;
    std::cin >> n;
    std::vector<ll> vec = {n};
    while (n!=1) {
        if (n&1) {
            n*=3;
            n+=1;
        } else {
            n/=2;
        }
        vec.push_back(n);
    }
    for (ll x : vec) std::cout << x << " ";
    std::cout << std::endl;
}