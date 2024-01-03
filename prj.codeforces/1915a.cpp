#include <iostream>

void solve()
{
	int a(0), b(0), c(0);
	std::cin >> a >> b >> c;
	if (a == b) std::cout << c << std::endl;
	else if (a == c) std::cout << b << std::endl;
	else if (b == c) std::cout << a << std::endl;
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