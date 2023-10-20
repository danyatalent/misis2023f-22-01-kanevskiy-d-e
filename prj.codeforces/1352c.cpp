#include <iostream>

long long solve()
{
	long long n(0), k(0);
	long long res(0);
	std::cin >> n >> k;
	if (k < n) {
		return k;
	}
	else {
		long long start(1), end(1e11);	
		while (start < end) {
			long long mid = start + (end - start) / 2;
			if ((mid - mid / n) >= k) {
				if (mid % n != 0) {
					res = mid;
				}
				end = mid;
			}
			else {
				start = mid + 1;
			}
		}
		return res;
	}
}

int main()
{
	int t(0);
	std::cin >> t;
	while (t--) {
		std::cout << solve() << std::endl;
	}

	return 0;
}