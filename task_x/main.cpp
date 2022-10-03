#include<iostream>
#include<vector>


int upper_bound(const std::vector<int> &a, int left, int right, int value) {
    
    while(left <= right) {

        int mid = (left + right) / 2;

        if (value > a[mid]) {
            left = mid + 1;
        }
        else  if (value < a[mid]) {
            right = mid - 1;
        }
        else {
            return mid;
        }
    }

    return left;
}

int calc(const std::vector<int> &a, int n, std::vector<int> &indexes) {

    const int infinity = 1e9+7;

    std::vector<int> len(n);
    std::vector<int> values(n, infinity);

    len[0] = 0;
    values[0] = a[0];

    int max_len = 1;

    for(size_t i = 1; i < n; ++i) {
        int index = upper_bound(values, 0, n, a[i]);

        while (values[index] < a[i]) {
            ++index;
        }
        if (values[index] == infinity) {
            max_len = index + 1;
        }

        values[index] = a[i];
        len[i] = index;
    }

    int cnt = max_len;
    int max_value = 1e9+7;

    for(int i = len.size() - 1; i >= 0 && cnt; --i) {

        if (len[i] == cnt - 1 && a[i] < max_value) {
            indexes[cnt - 1] = i;
            --cnt;
            max_value = a[i];
        }
    }

    return max_len;
}

int main() {

    int n;

    std::cin >> n;

    std::vector<int> a(n);

    for(size_t i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> indexes(n);

    int max_len = calc(a, n, indexes);

    std::cout << max_len << std::endl;

    for(size_t i = 0; i < max_len; ++i) {
        std::cout << indexes[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}