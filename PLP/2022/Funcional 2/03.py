lista = eval(input())
pares = list(filter(lambda x: x % 2 == 0, lista))

print(list(map(lambda x: x ** 3, pares)))
