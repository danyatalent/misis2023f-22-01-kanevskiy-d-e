#include <iostream>
#include <string>

int main()
{
	int t(0), n(0);
	std::string s;
	std::cin >> t;
	while (t != 0) {
		std::cin >> n >> s;
		int answer(0), balance(0);
		for (int i = 0; i < n; i += 1) {
			if (s[i] == '(') {
				balance += 1;
			}
			else {
				balance -= 1;
				if (balance < 0) {
					balance = 0;
					answer += 1;
				}
			}
		}
		std::cout << answer << std::endl;
		t -= 1;
	}
	return 0;
}