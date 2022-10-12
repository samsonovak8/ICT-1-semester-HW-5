#include <iostream>
#include <vector>

size_t calc(size_t n, size_t m) {
    std::vector<size_t> a(n + 1);
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
    size_t n = 0;
    size_t m = 0;

    std::cin >> n >> m;

    std::cout << calc(n, m);

    return 0;
}
