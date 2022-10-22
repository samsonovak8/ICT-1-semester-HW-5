#include <iostream>
#include <vector>

void calc_len(std::vector<std::vector<int> > &len, std::vector<std::vector<int> > &pred, int n, int m) {
  for (size_t j = 1; j <= m; ++j) {

    int mn1 = std::min(len[1][j - 1], len[2][j - 1]);
    len[1][j] += mn1;
    if(mn1 == len[1][j - 1]) {
        pred[1][j] = 1;
    }
    else {
        pred[1][j] = 2;
    }

    for (size_t i = 2; i < n; ++i) {

        int mn = std::min(len[i - 1][j - 1], std::min(len[i][j - 1], len[i + 1][j - 1]));

        len[i][j] += mn;

        if (mn == len[i - 1][j - 1]) {
            pred[i][j] = i - 1;
        }
        else if(mn == len[i][j - 1]) {
            pred[i][j] = i;
        }
        else {
            pred[i][j] = i + 1;
        }
    }

    int mn2 = std::min(len[n - 1][j - 1], len[n][j - 1]);
    len[n][j] += mn2;
    if (mn2 == len[n - 1][j - 1]) {
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

int find_path(std::vector<int> &path, std::vector<std::vector<int> > len, std::vector<std::vector<int> > pred, int n, int m) {
    int index = 1;
    for (size_t i = 2; i <= n; ++i) {

        if (len[i][m] < len[index][m]) {
            index = i;
        }
    }
    path[0] = -1;
    for (size_t i = 1; i <= n; ++i) {

        if (len[i][m] == len[index][m]) {

            std::vector<int> new_path(m);

            build_path(new_path, pred, i, m);

            /*for (size_t j = 0; j < m; ++j) {
                std::cout<<new_path[j]<<" ";
            }
            std::cout<<std::endl;*/

            choose_path(path, new_path);
        }
    }
    return len[index][m];
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

    calc_len(field, pred, n, m);

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
