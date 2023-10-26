#include <iostream>
#include <algorithm>

int main()
{
    int n(0), s(0);
    std::cin >> n >> s;
    int ans = s;
    for (int i = 0; i < n; i += 1) {
        int t(0), f(0);
        std::cin >> t >> f;
        ans = std::max(ans, t + f);
    }
    std::cout << ans << std::endl;
    return 0;
}