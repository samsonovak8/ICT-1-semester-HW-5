#include <iostream>
#include <vector>
#include <string>

int calc(std::string s1, std::string s2) {

    int n = s1.length();
    int m = s2.length();

    std::vector<std::vector<int> > dp(n + 1, std::vector<int> (m + 1, 0));

    for(int i = 0; i <= n; ++i) {

        for(int j = 0; j <= m; ++j) {

            if (!i && !j) {
                dp[i][j] = 0;
            }
            else if (!i) {
                dp[i][j] = j;
            }
            else if(!j) {
                dp[i][j] = i;
            }
            else {

                dp[i][j] = std::min(std::min(dp[i - 1][j], dp[i][j - 1]) + 1, dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));
            }

        }
    }
    return dp[n][m];
}

int main()
{
    std::string s1, s2;

    std::cin >> s1 >> s2;

    std::cout << calc(s1, s2) << std::endl;

    return 0;
}
