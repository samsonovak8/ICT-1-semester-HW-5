#include <iostream>
#include <vector>

void calc(std::vector<std::vector<int> > &dp, std::vector<std::vector<int> > &pred, int n, int m) {
  for (size_t j = 1; j <= m; ++j) {

    int mn1 = std::min(dp[1][j - 1], dp[2][j - 1]);
    dp[1][j] += mn1;
    if(mn1 == dp[1][j - 1]) {
        pred[1][j] = 1;
    }
    else {
        pred[1][j] = 2;
    }

    for (size_t i = 2; i < n; ++i) {

        int mn = std::min(dp[i - 1][j - 1], std::min(dp[i][j - 1], dp[i + 1][j - 1]));

        dp[i][j] += mn;

        if (mn == dp[i - 1][j - 1]) {
            pred[i][j] = i - 1;
        }
        else if(mn == dp[i][j - 1]) {
            pred[i][j] = i;
        }
        else {
            pred[i][j] = i + 1;
        }
    }

    int mn2 = std::min(dp[n - 1][j - 1], dp[n][j - 1]);
    dp[n][j] += mn2;
    if (mn2 == dp[n - 1][j - 1]) {
        pred[n][j] = n - 1;
    }
    else {
        pred[n][j] = n;
    }

  }
  return;
}

void build_path(std::vector<int> &path, std::vector<std::vector<int> > pred, int x, int y) {

    while (x && y) {
        path[y - 1] = x;
        x = pred[x][y];
        --y;
    }

    return;
}

void choose_path(std::vector<int> &path, std::vector<int> &new_path) {
    for (size_t i = 0; i < path.size(); ++i) {

        if (path[i] != new_path[i]) {

            if (path[i] > new_path[i] || path[i] == -1) {

                for (size_t j = 0; j < path.size(); ++j) {
                    path[j] = new_path[j];
                }

                break;
            }
        }
    }
    return;
}

int find_path(std::vector<int> &path, std::vector<std::vector<int> > dp, std::vector<std::vector<int> > pred, int n, int m) {
    int index = 1;
    for (size_t i = 2; i <= n; ++i) {

        if (dp[i][m] < dp[index][m]) {
            index = i;
        }
    }
    path[0] = -1;
    for (size_t i = 1; i <= n; ++i) {

        if (dp[i][m] == dp[index][m]) {

            std::vector<int> new_path(m);

            build_path(new_path, pred, i, m);

            /*for (size_t j = 0; j < m; ++j) {
                std::cout<<new_path[j]<<" ";
            }
            std::cout<<std::endl;*/

            choose_path(path, new_path);
        }
    }
    return dp[index][m];
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int> > field(n + 1, std::vector<int> (m + 1, 0));

    for (size_t i = 1; i <=n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            std::cin >> field[i][j];
        }
    }

    std::vector<std::vector<int> > pred(n + 1, std::vector<int> (m + 1, 0));

    calc(field, pred, n, m);

    std::vector<int> path(m);

    int ans = find_path(path, field, pred, n, m);

    /*for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            std::cout<<"("<<field[i][j]<<"; "<<pred[i][j]<<") ";
        }
        std::cout<<std::endl;
    }*/

    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i] << " ";
    }

    std::cout << std::endl << ans << std::endl;

    return 0;
}
