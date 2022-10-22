#include<iostream>
#include<string>
#include<vector>

int string_difference(std::string s1, std::string s2) {
    int n = s1.length();
    int m = s2.length();

    std::vector<std::vector<bool> > common_characters(n + 1, std::vector<bool> (m + 1, 0));

    common_characters[0][0] = 1;

    for(size_t j = 1; j <= m; ++j) {
        if (s2[j - 1] == '*') {
            common_characters[0][j] = common_characters[0][j - 1];
        }
    }

    for(size_t i = 1; i <= n; ++i) {
        
        for(size_t j = 1; j <= m; ++j) {

            if (s2[j - 1] == '*') {

                common_characters[i][j] = common_characters[i][j - 1] || common_characters[i - 1][j];
            }
            else if (s2[j - 1] == '?' || s1[i - 1] == s2[j - 1]) {

                common_characters[i][j] = common_characters[i - 1][j - 1];
            }
            else {

                common_characters[i][j] = 0;
            }
        }
    }

    return common_characters[n][m];
}

int main() {
    std::string s1;
    std::string s2;

    std::cin >> s1 >> s2;

    std::cout << (string_difference(s1, s2) == 1 ? "YES": "NO") << std::endl;

    return 0;
}