#include <algorithm>
#include <iostream>
#include <array>

int main() {
	int n(0), m(0);
	std::cin >> n >> m;
	std::array<int, 5005> type{ 0 };
	std::array<int, 5005> dp{ 0 };

	for (int i = 1; i <= n; i++) {
		double x;
		std::cin >> type[i] >> x;
	}

	for (int i = 1; i <= n; i++) {
		int j = type[i];
		for (int k = j; k >= 1; k--) {
			dp[j] = std::max(dp[j], 1 + dp[k]);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = std::max(ans, dp[i]);
	}
	std::cout << n - ans << std::endl;
}
