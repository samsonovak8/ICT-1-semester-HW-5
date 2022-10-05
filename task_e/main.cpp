#include <iostream>
#include <math.h>
#include <string>

std::string calc(int n) {
    int cnt = 2;
    while (cnt < n) {
        cnt += sqrt(cnt + sqrt(cnt) + 1) + 1;
        if (cnt == n) {
            return "Second";
        }
    }
    return "First";
}

int main()
{
    int n;

    std::cin >> n;

    std::cout << calc(n) << std::endl;

    return 0;
}
