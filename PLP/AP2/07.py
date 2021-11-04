def linha(M, l):
    return M[l]


def coluna(M, c):
    lista = []
    for i in range(len(M)):
        lista.append(linha(M, i)[c])
    return lista


def dot(vet_a, vet_b):
    prod = 0
    for i in range(len(vet_a)):
        prod += vet_a[i] * vet_b[i]
    return prod


def matmul(A, B):

    result = []
    for i in range(len(A)):
        temp = []
        for j in range(len(B[0])):
            temp.append(dot(linha(A, i), coluna(B, j)))
        result.append(temp)

    return result


A = [[1, 2, 3], [4, 5, 6]]
B = [[1, 2], [3, 4], [5, 6]]

print(matmul(A, B))
