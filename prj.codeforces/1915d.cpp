#include <iostream>
#include <string>

void solve()
{
    int n(0);
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::string res = "";

    while (!s.empty()) {
        int tmp = 0;
        if (s.back() == 'a' || s.back() == 'e') {
            tmp = 2;
        }
        else tmp = 3;
        while (tmp--) {
            res += s.back();
            s.pop_back();
        }
        res += '.';
    }
    res.pop_back();
    std::reverse(res.begin(), res.end());
    std::cout << res << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int t(0);
    std::cin >> t;
    while (t--) {
        solve();
    }
}