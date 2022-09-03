def has_divisors(n, m = 3):
    if m**2 > n:
        return False
    elif n % m == 0:
        return True
    else:
        has_divisors(n, m+2)


def primo(n):
    if n == 2:
        return True
    elif n % 2 == 0 or n < 2:
        return False
    elif has_divisors(n, 3):
        return False


if __name__ == '__main__':
    entrada = eval(input())
    for num in entrada:
        if primo(num):
            print(num, "eh primo")
        else:
            print(num, "nao eh primo")
