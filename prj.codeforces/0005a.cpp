#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s;
    std::vector <std::string> chat;
    int ans = 0;
    while (getline(std::cin, s)) {
        if (s[0] == '+') {
            chat.push_back(s.substr(1, s.size()));
        }
        else if (s[0] == '-') {
            std::vector<std::string>::iterator position = std::find(chat.begin(), chat.end(), s.substr(1));
            chat.erase(position);
        }
        else {
            int len_tmp = 0;
            for (int i = s.find(':') + 1; i < s.size(); i += 1) len_tmp += 1;
            len_tmp *= chat.size();
            ans += len_tmp;
        }
    }
    std::cout << ans << std::endl;
}