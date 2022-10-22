#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
 
void find_half_palidrome(std::string s, std::unordered_map<std::string, int>& cnt) {
    size_t len = s.size();
    for (size_t mask = 1; mask <= ((1 << len) - 1); ++mask) {
        std::string kek = "";
        for (int i = 0; i < len; i++) {
            if ((mask >> i) & 1)
                kek.push_back(s[i]);
        }
        cnt[kek]++;
    }
    return;
}

int find_string_answer(size_t n, std::unordered_map<std::string, int>& cnt_left, std::unordered_map<std::string, int>& cnt_right, std::string s) {
    int ans = 0;
    cnt_left[""] = 1;
    cnt_right[""] = 1;
    for (int len = 1; len <= n; len++) {
        for (int len_left = 0; len_left <= n / 2; len_left++) {
            if (len - len_left > len_left || len_left > len)
                continue;
            for (auto el : cnt_left) {
                if (el.first.size() != len_left)
                    continue;
                int len_right = len - len_left;
                bool fl = true;
                for (int i = len_right; i < len_left; i++) {
                    if (el.first[i] != el.first[len_left - (i - len_right) - 1]) {
                        fl = false;
                        break;
                    }
                }
                if (!fl)
                    continue;
                std::string right = "";
                for (int i = len_right - 1; i >= 0; i--)
                    right.push_back(el.first[i]);
                ans += el.second * cnt_right[right];
            }
        }
    }
    for (int len = 1; len <= n; len++) {
        for (int len_right = 0; len_right <= n - n / 2; len_right++) {
            if (len - len_right >= len_right || len_right > len)
                continue;
            for (auto el : cnt_right) {
                if (el.first.size() != len_right)
                    continue;
                int len_left = len - len_right;
                bool fl = true;
                for (int i = 0; i < len_right - len_left; i++) {
                    if (el.first[i] != el.first[len_right - len_left - i - 1]) {
                        fl = false;
                        break;
                    }
                }
                if (!fl)
                    continue;
                std::string left = "";
                for (int i = len_right - 1; i >= len_right - len_left; i--)
                    left.push_back(el.first[i]);
                ans += el.second * cnt_left[left];
            }
        }
    }
    return ans;
}
 
int main() {
    std::string s;
    std::cin >> s;
    size_t n = (size_t)s.size();
    std::unordered_map<std::string, int> cnt_left, cnt_right;
    if (n <= 1) {
        find_half_palidrome(s, cnt_left);
        int ans = 0;
        for (auto el : cnt_left) {
            ans += el.second;
        }
        std::cout << ans << "\n";
        return 0;
    }
    std::string l = "", r = "";
    for (int i = 0; i < n / 2; i++)
        l.push_back(s[i]);
    for (int i = n / 2; i < n; i++)
        r.push_back(s[i]);
    find_half_palidrome(l, cnt_left);
    find_half_palidrome(r, cnt_right);
    std::cout << find_string_answer(n, cnt_left, cnt_right, s);
    
    return 0;
}
