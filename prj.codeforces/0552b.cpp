#include <iostream>
typedef long long ll;

ll i, n, x, m, k, ans;
int main()
{
	long long n(0), x(0), k(0), ans(0);
	int m(0);
	std::cin >> n;
	x = n;
	while (x)
	{
		x /= 10;
		m++;
	}
	ans = n * m + m - 1;
	k = 1;
	for (int i = 0; i < m - 1; i++)
	{
		k *= 10;
		ans -= k;
	}
	std::cout << ans << std::endl;
	return 0;
}