#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int calc(std::string s1, std::string s2, int n, int m) {
    std::vector<std::vector<int> > dp(2, std::vector<int> (m + 1));
    int ans=0;
    for (size_t i = 1; i <= n; ++i) {

        for (size_t j = 1; j <= m; ++j) {

            if (s1[i - 1] == s2[j - 1]) {
                dp[i % 2][j] = dp[(i + 1) % 2][j - 1] + 1;
            }
            else {
                dp[i % 2][j] = 0;
            }

            ans = std::max(ans, dp[i % 2][j]);
        }
    }
    return ans;
}

std::string calc(std::string s1, std::string s2, int n, int m, int max_len) {
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

    int n = s1.length();
    int m = s2.length();

    int ans = calc(s1, s2, n, m);

    std::cout << calc(s1, s2, n, m, ans) << std::endl;

    return 0;
}
