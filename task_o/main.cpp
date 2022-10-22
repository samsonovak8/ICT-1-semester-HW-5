#include<iostream>
#include<string>
#include<utility>
#include<vector>


bool check_index(int i, int j, int n, int m) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

void fill_adjacency_matrix(std::vector<std::vector<char> >a, std::vector<std::vector<int> > b,std::vector<std::vector<long long int> > &c, int n, int m, int cnt) {
    for(size_t i = 0; i < n; ++i) {

        for(size_t j = 0; j < m; ++j) {

            if (a[i][j] != '+') {

                if (check_index(i - 1, j, n, m) && a[i - 1][j] != '+') {

                    int x = b[i - 1][j];
                    int y = b[i][j];

                    c[x][y] = c[y][x] = 1;
                }

                if (check_index(i, j - 1, n, m) && a[i][j - 1] != '+') {

                    int x = b[i][j - 1];
                    int y = b[i][j];

                    c[x][y] = c[y][x] = 1;
                }

                if (check_index(i + 1, j, n, m) && a[i + 1][j] != '+') {

                    int x = b[i + 1][j];
                    int y = b[i][j];

                    c[x][y] = c[y][x] = 1;
                }

                if (check_index(i, j + 1, n, m) && a[i][j + 1] != '+') {

                    int x = b[i][j + 1];
                    int y = b[i][j];

                    c[x][y] = c[y][x] = 1;
                }

            }
        }
    }
    return;
}

std::vector<std::vector<long long int> > operator*(std::vector<std::vector<long long int> > a, std::vector<std::vector<long long int> > b) {
    std::vector<std::vector<long long int> > c(a.size(), std::vector<long long int>(b[0].size()));

    for(size_t i = 0; i < a.size(); ++i) {
        for(size_t j = 0; j < b[0].size(); ++j) {
            c[i][j] = 0;
            for(size_t k = 0; k < a[0].size(); ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

void binpow(std::vector<std::vector<long long int> > &c, int n, int degree) {
    std::vector<std::vector<long long int> > res(n, std::vector<long long int>(n, 0));

    for(size_t i = 0; i < n; ++i) {
        res[i][i] = 1;
    }
    while(degree) {
        if (degree&1) {
            res = res * c;
        }
        c = c * c;
        degree >>= 1;
    }

    for(size_t i = 0; i < n; ++i) {
        for(size_t j = 0; j < n; ++j) {
            c[i][j] = res[i][j];
        }
    }
    return;
}

int main()
{
    int n;
    int m;
    int k;
    std::cin >> n >> m >> k;

    std::string s;
    std::pair<int, int> start, finish;

    std::vector<std::vector<char> > a(n, std::vector<char> (m));
    std::vector<std::vector<int> > b(n, std::vector<int> (m));
    int cnt = 0;

    for(size_t i = 0; i < n; ++i) {

        std::cin >> s;
        for(size_t j = 0; j < m; ++j) {

            a[i][j] = s[j];
            b[i][j] = cnt++;

            if (s[j] == '@') {
                start.first = i;
                start.second = j;
            }
            else if (s[j] == '#') {
                finish.first = i;
                finish.second = j;
            }
        }
    }

    std::vector<std::vector<long long int> > c(cnt, std::vector<long long int> (cnt));

    fill_adjacency_matrix(a, b, c, n, m, cnt);

    binpow(c, cnt, k);

    int start_point = b[start.first][start.second];
    int finish_point = b[finish.first][finish.second];

    std::cout << c[start_point][finish_point] << std::endl;

    return 0;
}
