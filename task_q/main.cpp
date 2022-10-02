#include<iostream>
#include<vector>

long long int calc(std::vector<std::vector<long long int> > &dp, std::vector<long long int> a, int left, int right) {

    if (left == right) {
        return 0;
    }

    if (dp[left][right] != -1) {
        return dp[left][right];
    }

    long long int answer = 1e18+7;

    for(size_t mid = left; mid < right; ++mid) {

        long long int temp_answer = calc(dp, a, left, mid) + calc(dp, a, mid + 1, right) + a[left - 1] * a[mid] * a[right];

        answer = std::min(answer, temp_answer);
    }

    return dp[left][right] = answer;
}

int main() {
    int n;

    std::cin >> n;

    std::vector<long long int> a(n);

    for(size_t i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<std::vector<long long int> > dp(n, std::vector<long long int>(n, -1));

    std::cout << calc(dp, a, 1, n - 1) << std::endl;

    return 0;
}