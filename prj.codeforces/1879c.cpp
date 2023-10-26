#include <iostream>
#include <string>


const int MOD = 998244353;

void upd(int& a, int b) {
	a = (a * 1LL * b) % MOD;
}

void solve()
{
	std::string s;
	std::cin >> s;
	int res = 1;
	int k = s.size();
	int n = s.size();
	for (int l = 0; l < n; ) {
		int r = l + 1;
		while (r < n && s[l] == s[r])
			++r;
		upd(res, r - l);
		--k;
		l = r;
	}
	for (int i = 1; i <= k; ++i)
		upd(res, i);
	std::cout << k << ' ' << res << std::endl;
}


int t;
std::string s;

int main() {
	std::cin >> t;
	while (t--) {
		solve();
	}
}