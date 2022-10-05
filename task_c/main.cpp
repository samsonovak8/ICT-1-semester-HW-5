#include <iostream>
#include <vector>
#include <algorithm>

int calc(size_t n, std::vector<int> a) {

    std::vector<int> dp(n);
    dp[0] = 1e9+7;
    dp[1] = a[1] - a[0];

    for (size_t i = 2; i < n; ++i) {

        dp[i] = std::min(dp[i - 2], dp[i - 1]) + a[i] - a[i - 1];
    }

    return dp[n - 1];
}

int main() {

    int *n = new int;

    std::cin >> *n;

    std::vector<int> a(*n);

    for (size_t i = 0; i < *n; ++i) {

        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    std::cout << calc(*n, a);

    delete n;
    n = nullptr;

    return 0;
}