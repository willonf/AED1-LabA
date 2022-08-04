def recursive_binary_search(exclude, lista, elemento, low=0, high=None):
    if high is None:
        final = len(lista) - 1
    if high < low:
        return False
    mid = low + (high - low) // 2
    if lista[mid] == elemento and mid != exclude:
        return lista[mid]
    if lista[mid] < elemento:
        return recursive_binary_search(exclude, lista, elemento, mid + 1, high)
    return recursive_binary_search(exclude, lista, elemento, low, mid-1)


def f(L, x):
    result = 'nao'
    for n1 in L:
        index = L.index(n1)
        n2 = recursive_binary_search(index, L, x - n1, 0, len(L) - 1)
        if n2 and n1 + n2 == x and n1 != n2:
            result = 'sim'
            break
    return result


lista = eval(input())
casos = eval(input())

for caso in casos:
    print(f(lista, caso))
