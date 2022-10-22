#include <iostream>
#include <vector> 

int mask_dp(size_t n, size_t m, std::vector<int> &d, std::vector<std::vector<int> > &c) {

    std::vector<std::vector<int> > sum(n, std::vector<int>(1 << m));
    for(size_t i = 0; i < n; ++i) {
        sum[i][0] = d[i];
    }

    for(size_t i = 0; i < n; ++i) {
        for(size_t mask = 1; mask < (1 << m); ++mask) {

            int min = 1e9+7;

            for(size_t j = 0; j < m; ++j) {
                if (mask & (1 << j)) {
                    if (i)
                        min = std::min(sum[i - 1][mask^(1<<j)] + d[i] + c[i][j], min);
                    min = std::min(sum[i][mask^(1<<j)] + c[i][j], min);
                }
            }
            sum[i][mask] = min;
        }
        if (i) {
            for(size_t mask = 1; mask < (1 << m); ++mask) {
                sum[i][mask] = std::min(sum[i][mask], sum[i -1][mask]);
            }
        }
        
    }
    return sum[n - 1][(1 << m) - 1];
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    std::vector<int> d(n);
    std::vector<std::vector<int> > c(n, std::vector<int> (m));

    for(size_t i = 0; i < n; ++i) {
        std::cin >> d[i];

        for(size_t j = 0; j < m; ++j) {
            std::cin >> c[i][j];
        }
    }

    std::cout << mask_dp(n, m, d, c) << std::endl;


    return 0;
}