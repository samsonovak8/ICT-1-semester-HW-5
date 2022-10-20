#include <iostream>

char calc(size_t n, size_t m) {
    char ans;
    if (n == m) {
        ans = 'F';
    }
    else if (n == 2 || m == 2) {
        ans = 'S';
    }
    else if (n==3 || m == 3) {
        ans = 'F';
    }
    else if (n-m==2 || m-n==2) {
        ans = 'S';
    }
    else {
        ans = 'F';
    }
    return ans;
}

int main()
{
    size_t n = 0;
    size_t m = 0;

    std::cin >> n >> m;

    std::cout << calc(n, m) << std::endl;

    return 0;
}
