#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::cin >> s;
	if (s.size() == 1) {
		if (islower(s[0])) s[0] = toupper(s[0]);
		else s[0] = tolower(s[0]);
		std::cout << s << std::endl;
	}
	else {
		bool error = true;
		for (int i = 1; i < s.size(); i += 1) {
			if (islower(s[i])) error = false;
		}
		if (error) {
			if (islower(s[0])) s[0] = toupper(s[0]);
			else s[0] = tolower(s[0]);
			for (int i = 1; i < s.size(); i += 1) s[i] = tolower(s[i]);
		}
		std::cout << s << std::endl;
	}
	return 0;
}