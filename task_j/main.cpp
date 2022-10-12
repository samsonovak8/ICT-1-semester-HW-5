#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

void precalc(size_t n, std::vector<std::vector<int> > a, std::vector<std::vector<int> > &dp) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (!a[i][j]) {
                dp[i][j] = i;
            }
            else if (i) {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return;
}

void free_stack(std::stack<int> &st) {
    while(!st.empty()) {
        st.pop();
    }
    return;
}

int calc(size_t n, std::vector<std::vector<int> > dp) {
    std::stack<int> st;
    std::vector<int> left(n), right(n);
    int ans = 0;

    for (size_t i = 0; i < n; ++i) {

        free_stack(st);

        for (size_t j = 0; j < n; ++j) {
            while (!st.empty() && dp[i][st.top()] <= dp[i][j]) {
                st.pop();
            }
            left[j] = st.empty() ? -1 : st.top();
            st.push(j);
        }

        free_stack(st);

        for (int j = n - 1; j >= 0; --j) {
            while (!st.empty() && dp[i][st.top()] <= dp[i][j]) {
                st.pop();
            }
            right[j] = st.empty() ? n : st.top();
            st.push(j);
        }

        for (size_t j = 0; j < n; ++j) {
            int length = std::min((int)right[j] - left[j] - 1, (int)i - dp[i][j]);
            ans = std::max(ans, length);
        }
    }

    return ans;
}

int main() {
    int n;

    std::cin >> n;

    std::vector<std::vector<int> > a(n, std::vector<int> (n));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
                std::cin >> a[i][j];
        }
    }

    std::vector<std::vector<int> > dp(n, std::vector<int> (n, -1));

    precalc(n, a, dp);

    std::cout << calc(n, dp);

    return 0;
}