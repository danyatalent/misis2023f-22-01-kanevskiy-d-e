#include <iostream>

int main()
{
    long long n(0), m(0), pos(1), res(0), temp(0);
    std::cin >> n >> m;
    for (int i = 0; i < m; i += 1) {
        std::cin >> temp;
        if (temp < pos) res += n - pos + temp;
        else res += temp - pos;
        pos = temp;
    }
    std::cout << res << std::endl;
    return 0;
}