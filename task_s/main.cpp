#include <cstdint>
#include <iostream>
#include <vector>

bool check(int n, int k) {
    if (k == 1) {
        std::cout << n - 1 << std::endl;
        return 1;
    }

    if (!k && n > 1) {
        std::cout << -1 << std::endl;
        return 1;
    }
    return 0;
}

int find_max_height(long long int n, int k) {
    std::vector<std::vector<long long int> > height(2);

    height[0].push_back(1);
    long long int sum = 1;
    int cnt = k + 1;
    int cur_floor = 1;
    int flag = 1;
    while(sum < n) {

        sum = 0;

        if(cnt) {
            ++sum;
            --cnt;
        }

        height[flag].push_back(1);

        for(size_t i = 1; i < cur_floor; ++i) {
            height[flag].push_back(height[!flag][i - 1] + height[!flag][i]);

            if (cnt) {
                sum += height[!flag][i - 1] + height[!flag][i];
                --cnt;
            }
        }

        if (cnt) {
            ++sum;
            --cnt;
        }
        
        height[flag].push_back(1);
        height[!flag].clear();
        flag ^= 1;
        cnt = k + 1;
        ++cur_floor;
    }

    return cur_floor - 1;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    if (check(n, k)) {
        return 0;
    }
    else {
        std::cout << find_max_height(n, k) << std::endl;
    }
    return 0;
}
