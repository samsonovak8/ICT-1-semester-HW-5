#include <iostream>
#include <vector>
#include <iomanip>

long double calc(size_t n, size_t m) {

    std::vector<std::vector<long double> > dp(n + 1, std::vector<long double> (m + 1, 0.0));

    dp[0][0] = 1.0;

    for(int i = 0; i < n; ++i) {

        for(int j = 0; j < m; ++j) {

            for(int k = 1; k <= 6; ++k) {

                if(j + k <= m) {
                    dp[i + 1][j + k] += dp[i][j] / 6;
                }
            }
        }
    }
    return dp[n][m];
}

int main()
{
    size_t n = 0;
    size_t m = 0;

    std::cin >> n >> m;

    double ans = calc(n, m);

    std::cout << std::fixed << std::setprecision(9) << ans << std::endl;

    return 0;
}
