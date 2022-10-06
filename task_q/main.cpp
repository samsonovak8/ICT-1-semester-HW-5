#include<iostream>
#include<vector>

long long int recursive_find_answer(std::vector<std::vector<size_t> > &dp, std::vector<size_t> a, size_t left, size_t right) {

    if (left == right) {
        return 0;
    }

    size_t answer = 1e18+7;

    if (dp[left][right] != answer) {
        return dp[left][right];
    }

    for(size_t mid = left; mid < right; ++mid) {

        size_t temp_answer = recursive_find_answer(dp, a, left, mid) + recursive_find_answer(dp, a, mid + 1, right) + a[left - 1] * a[mid] * a[right];

        answer = std::min(answer, temp_answer);
    }

    return dp[left][right] = answer;
}

int main() {
    size_t n;

    std::cin >> n;

    std::vector<size_t> a(n);

    for(size_t i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    const size_t inf=1e18+7;

    std::vector<std::vector<size_t> > dp(n, std::vector<size_t>(n, inf));

    std::cout << recursive_find_answer(dp, a, 1, n - 1) << std::endl;

    return 0;
}