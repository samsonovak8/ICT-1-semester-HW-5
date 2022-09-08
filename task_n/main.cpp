#include <iostream>
#include <vector>

long long calc(std::vector<long long> a) {
    int n = a.size();
    long long sum = 0;
    long long res = -1e9-7;
    for(int i = 0; i < n; ++i) {

        sum += a[i];
        res = std::max(res, sum);

        if (sum < 0) {
            sum = 0;
        }
    }
    return res;
}

long long calc(std::vector<std::vector<long long> > matrix, int n, int m) {

    long long ans = -1e9-7;

    for(int i = 0; i < n; ++i) {

        std::vector<long long> sum(m, 0);

        for(int j = i; j < n; ++j) {

            for(int z = 0; z < m; ++z) {

                sum[z]+=matrix[j][z];
            }
            ans = std::max(ans, calc(sum));
        }
    }
    return ans;
}

int main()
{
    int n, m;

    std::cin >> n >> m;

    std::vector<std::vector<long long> > matrix(n, std::vector<long long> (m));

    for(int i=0; i<n; ++i) {

        for(int j=0; j<m; ++j) {

            std::cin>>matrix[i][j];
        }
    }
    std::cout << calc(matrix, n, m) << std::endl;
    return 0;
}
