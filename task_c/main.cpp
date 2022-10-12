#include <algorithm>
#include <iostream>
#include <vector>

int calc_min_ropes_length(size_t n, std::vector<int> a) {

    std::vector<int> min_length(n);
    min_length[0] = 1e9+7;
    min_length[1] = a[1] - a[0];

    for (size_t i = 2; i < n; ++i) {

        min_length[i] = std::min(min_length[i - 2], min_length[i - 1]) + a[i] - a[i - 1];
    }

    return min_length[n - 1];
}

int main() {

    int n;

    std::cin >> n;

    std::vector<int> a(n);

    for (size_t i = 0; i < n; ++i) {

        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    std::cout << calc_min_ropes_length(n, a);

    return 0;
}
