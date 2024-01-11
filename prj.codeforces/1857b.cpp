#include <iostream>
#include <string>

void solve()
{
    std::string s;
    std::cin >> s;
    s = '0' + s;
    int p = s.size();
    for (int i = s.size() - 1; i >= 0; i -= 1)
    {
        if (s[i] >= '5') {
            s[i - 1]++;
            p = i;
        }
    }
    for (int i = (s[0] == '0'); i < s.size(); i += 1) {
        if (i >= p) {
            std::cout << '0';
        }
        else {
            std::cout << s[i];
        }
    }
    std::cout << std::endl;
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