import sys


def potencia(numbers, exp=2):
    if exp == 0:
        return 1
    else:
        return potencia(number, exp - 1) * number


results = []
for caso in map(eval, sys.stdin):
    for number in caso:
        result = potencia(caso)
        results.append(result)
    print(results)
    results = []
