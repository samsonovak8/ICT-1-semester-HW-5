def calc(n, m):
    t_size = (n // 2) * m + 1
    current_digit = [0] * t_size

    for i in range(0, m + 1):
        current_digit[i] = 1

    for i in range(1, n // 2):

        next_digit = [0] * t_size

        for j in range(t_size):
            for k in range(min(j + 1, m + 1)):
                next_digit[j] += current_digit[j - k]
        
        for j in range(t_size):
            current_digit[j] = next_digit[j]
    
    ans = 0
    for i in range(t_size):
        ans += current_digit[i]**2
    
    return ans

n, m = list(map(int, input().split()))
 
print(calc(n, m - 1))