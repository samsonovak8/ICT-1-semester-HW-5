#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

size_t find_lenth_common_substr(std::string s1, std::string s2, size_t n, size_t m) {
    std::vector<std::vector<size_t> > dp(2, std::vector<size_t> (m + 1));
    size_t max_length=0;
    for (size_t i = 1; i <= n; ++i) {

        for (size_t j = 1; j <= m; ++j) {

            if (s1[i - 1] == s2[j - 1]) {
                dp[i % 2][j] = dp[(i + 1) % 2][j - 1] + 1;
            }
            else {
                dp[i % 2][j] = 0;
            }

            max_length = std::max(max_length, dp[i % 2][j]);
        }
    }
    return max_length;
}

std::string build_answer_string(std::string s1, std::string s2, size_t n, size_t m, size_t max_len) {
    std::string ans_string="";
    std::vector<std::vector<int> > dp(2, std::vector<int> (m + 1));
    for (size_t i = 1; i <= n; ++i) {

        for (size_t j = 1; j <= m; ++j) {

            if (s1[i - 1] == s2[j - 1]) {
                dp[i % 2][j] = dp[(i + 1) % 2][j - 1] + 1;
            }
            else {
                dp[i % 2][j] = 0;
            }

            if (dp[i % 2][j] == max_len) {
                std::string ans_string2 = s1.substr(i - max_len, max_len);
                if (ans_string == "" || ans_string > ans_string2) {
                    ans_string = ans_string2;
                }
            }

        }
    }

    return ans_string;
}

int main() {
    std::string s1, s2;

    std::cin >> s1 >> s2;

    size_t n = s1.length();
    size_t m = s2.length();

    size_t ans = find_lenth_common_substr(s1, s2, n, m);

    std::cout << build_answer_string(s1, s2, n, m, ans) << std::endl;

    return 0;
}
