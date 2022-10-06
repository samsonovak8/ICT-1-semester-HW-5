#include <iostream>

char calc(int n, int m) {
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
    int *n = new int;
    int *m = new int;

    std::cin >> *n >> *m;

    std::cout << calc(*n, *m) << std::endl;

    delete n;
    n = nullptr;
    delete m;
    m = nullptr;

    return 0;
}
