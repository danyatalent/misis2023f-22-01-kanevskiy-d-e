#include <iostream>

void solve()
{
    int cnt = 0;
    int n(0);
    std::cin >> n;
    for (int i = 0; i < n; i += 1) {
        int tmp(0);
        std::cin >> tmp;
        if (tmp % 2 != 0) {
            cnt += 1;
        }
    }
    if (cnt % 2 == 0) {
        std::cout << "yes" << std::endl;
    }
    else {
        std::cout << "no" << std::endl;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t(0);
    std::cin >> t;
    while (t--) {
        solve();
    }
}