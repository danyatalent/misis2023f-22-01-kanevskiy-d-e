#include <iostream>
#include <string>
#include <map>


void solve()
{
    int n(0), k(0);
    std::string s;
    std::cin >> n >> k >> s;
    std::map<char, int> letters;
    for (int i = 0; i < n; i += 1) {
        if (auto search = letters.find(s[i]); search != letters.end()) {
            letters[s[i]] += 1;
        }
        else {
            letters[s[i]] = 1;
        }
    }
    int cnt_odd(0);
    for (auto element : letters) {
        if (element.second % 2 != 0) cnt_odd += 1;
    }
    if (cnt_odd <= k + 1) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;
}


int main()
{
    int t(0);
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}