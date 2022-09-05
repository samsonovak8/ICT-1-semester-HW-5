#include <iostream>
#include <vector>

void calc(size_t n, size_t s, std::vector<int> a, std::vector<int> &dp, std::vector<int> &pred) {
    dp[0] = 0;
    for (size_t i = 0; i <= s; ++i)
    {
        for(size_t j = 0; j < n; ++j)
        {
            if (i + a[j] <= s && dp[i + a[j]] > dp[i] + 1)
            {
                dp[i + a[j]] = dp[i] + 1;
                pred[i + a[j]] = a[j];
            }
        }
    }
    return;
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> a(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    size_t s, inf = 1e9+7;
    std::cin >> s;
    std::vector<int> dp(s + 1, inf), pred(s + 1);
    calc(n, s, a, dp, pred);
    if (dp[s] == inf) {
        std::cout << -1;
    }
    else {
        std::cout << dp[s] << std::endl;
        while (s > 0) {
            std::cout << pred[s];
            s -= pred[s];
            if (s)
                std::cout << " ";
        }
    }
    return 0;
}
