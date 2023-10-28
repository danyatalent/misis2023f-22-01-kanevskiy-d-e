#include <iostream>
#include <vector>

void solve()
{
    int n(0);
    std::cin >> n;
    std::vector<int> fence;
    fence.resize(n + 1);
    for (int i = 1; i <= n; i += 1) {
        std::cin >> fence[i];
    }
    if (fence[1] != n) {
        std::cout << "no" << std::endl;
        return;
    }
    else {
        std::vector<int> fence_horizont;
        for (int i = n; i >= 1; i -= 1) {
            while (fence_horizont.size() < fence[i]) {
                fence_horizont.push_back(i);
            }
        }
        bool flag = true;
        for (int i = 1; i <= n; i += 1) {
            if (fence[i] != fence_horizont[i - 1]) {
                std::cout << "no" << std::endl;
                flag = false;
                break;
            }
        }
        if (flag) std::cout << "yes" << std::endl;
    }
}


int main()
{
    int t(0);
    std::cin >> t;
    while (t--) solve();
    return 0;
}