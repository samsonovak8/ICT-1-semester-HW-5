#include<iostream>
#include<string>
#include<vector>

int calc(std::string s1, std::string s2) {
    int n = s1.length();
    int m = s2.length();

    std::vector<std::vector<bool> > dp(n + 1, std::vector<bool> (m + 1, 0));

    dp[0][0] = 1;

    for(size_t j = 1; j <= m; ++j) {
        if (s2[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for(size_t i = 1; i <= n; ++i) {
        
        for(size_t j = 1; j <= m; ++j) {

            if (s2[j - 1] == '*') {

                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
            else if (s2[j - 1] == '?' || s1[i - 1] == s2[j - 1]) {

                dp[i][j] = dp[i - 1][j - 1];
            }
            else {

                dp[i][j] = 0;
            }
        }
    }

    return dp[n][m];
}

int main() {
    std::string s1;
    std::string s2;

    std::cin >> s1 >> s2;

    std::cout << (calc(s1, s2) == 1 ? "YES": "NO") << std::endl;

    return 0;
}