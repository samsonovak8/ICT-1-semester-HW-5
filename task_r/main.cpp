#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
 
int find_min_sum(size_t n, size_t m, std::vector<int> &a, std::vector<int> &now) {

    int min_cost[300][300 + 1];
    std::pair <int, int> parent[300][300 + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            min_cost[i][j] = 1e9;
            parent[i][j] = {0, 0};
        }
    }
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            s += std::abs(a[i] - a[j]);
        }
        min_cost[i][1] = s;
    }
    for (int cnt = 2; cnt <= m; cnt++) {
        for (int last = cnt - 2; last < n; last++) {
            for (int pos = last + 1; pos < n; pos++) {
                int s = min_cost[last][cnt - 1];
                for (int j = last + 1; j < n; j++)
                    s -= (a[j] - a[last]);
                for (int j = last + 1; j < n; j++)
                    s += std::min(a[j] - a[last], std::abs(a[pos] - a[j]));
                if (min_cost[pos][cnt] > s) {
                    min_cost[pos][cnt] = s;
                    parent[pos][cnt] = {last, cnt - 1};
                }
            }
        }
    }
    int ans = 1e9, pos = -1;
    for (int i = 0; i < n; i++) {
        if (ans > min_cost[i][m]) {
            ans = min_cost[i][m];
            pos = i;
        }
    }

    now.push_back(a[pos]);

    int cnt = m;
    while (now.size() < m) {
        pos = parent[pos][cnt].first;
        cnt--;
        now.push_back(a[pos]);
    }
    std::reverse(now.begin(), now.end());
    return min_cost[n][m];
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);

    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    std::vector <int> now;

    std::cout << find_min_sum(n, m, a, now) << std::endl;

    for (int e : now)
        std::cout << e << " ";

    return 0;
}
