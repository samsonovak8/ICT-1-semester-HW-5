#include <iostream>
#include <vector>

int calc(int n, int m) {
    std::vector<int> a(n + 1);
    a[0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = i - 1; j >= std::max(i - m, 0); --j) {
            a[i] += a[j];
        }
    }
    return a[n];
}

int main()
{
    int n, m;

    std::cin >> n >> m;

    std::cout << calc(n, m);

    return 0;
}
