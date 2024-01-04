#include <iostream>
#include <array>

#define ll long long
const int MAX_N = 20001;


bool is_square(ll x) {
    ll l = 1, r = 1e9;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (mid * mid == x) return true;
        if (mid * mid > x) r = mid - 1;
        else l = mid + 1;
    }
    return false;
}

void solve()
{

    int n(0);
    std::cin >> n;
    ll sum(0);
    for (int i = 0; i < n; i += 1) {
        ll tmp = 0;
        std::cin >> tmp;
        sum += tmp;
    }
    if (is_square(sum)) std::cout << "yes" << std::endl;
    else std::cout << "no" << std::endl;
}

int main()
{
    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }
}