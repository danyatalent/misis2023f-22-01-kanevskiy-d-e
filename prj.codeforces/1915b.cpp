#include <iostream>
#include <array>

void solve()
{
    int x(0), y(0);
    std::array<std::array<char, 3>, 3> quad;
    for (int i = 0; i < 3; i += 1) {
        for (int j = 0; j < 3; j += 1) {
            char tmp = ' ';
            std::cin >> tmp;
            if (tmp == '?') {
                x = j;
                y = i;
            }
            quad[i][j] = tmp;
        }
    }

    int a_(0), b_(0), c_(0);
    for (int i = 0; i < 3; i += 1) {
        if (quad[y][i] == 'A') a_ += 1;
        if (quad[y][i] == 'B') b_ += 1;
        if (quad[y][i] == 'C') c_ += 1;
    }
    for (int i = 0; i < 3; i += 1) {
        if (quad[i][x] == 'A') a_ += 1;
        if (quad[i][x] == 'B') b_ += 1;
        if (quad[i][x] == 'C') c_ += 1;
    }

    if (a_ == 0) std::cout << 'A' << std::endl;
    if (b_ == 0) std::cout << 'B' << std::endl;
    if (c_ == 0) std::cout << 'C' << std::endl;
}

int main()
{
    int t(0);
    std::cin >> t;
    while (t--)
    {
        solve();
    }
}