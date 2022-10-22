#include <iostream>
#include <vector>
#include <string>

int find_difference(std::string s1, std::string s2) {

    int n = s1.length();
    int m = s2.length();

    std::vector<std::vector<int> > diff(n + 1, std::vector<int> (m + 1, 0));

    for(int i = 0; i <= n; ++i) {

        for(int j = 0; j <= m; ++j) {

            if (!i && !j) {
                diff[i][j] = 0;
            }
            else if (!i) {
                diff[i][j] = j;
            }
            else if(!j) {
                diff[i][j] = i;
            }
            else {

                diff[i][j] = std::min(std::min(diff[i - 1][j], diff[i][j - 1]) + 1, diff[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));
            }

        }
    }
    return diff[n][m];
}

int main()
{
    std::string s1, s2;

    std::cin >> s1 >> s2;

    std::cout << find_difference(s1, s2) << std::endl;

    return 0;
}
