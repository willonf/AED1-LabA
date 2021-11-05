# Usando as funções head e tail,
# escreva uma função pertence(x, L), livre de efeitos colaterais,
# que retorna True se o elemento x pertence à lista.
# Não indexe a lista diretamente.

def head(L):
    return L[0]


def tail(L):
    return L[1:]


def pertence(x, L):
    if x == head(L) or x in tail(L):
        return True
    return False


lista = [x for x in range(20)]

print(lista)
print(pertence(11, lista))
