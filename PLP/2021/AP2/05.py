def linha(M, l):
    return M[l]


def coluna(M, c):
    lista = []
    for i in range(len(M)):
        lista.append(linha(M, i)[c])
    return lista


def sudou_valido(matriz_sudoku):
    for linha in sudoku:
        for num in linha:
            if linha.count(num) > 1:
                return False

    for c in range(len(sudoku[0])):
        col = coluna(matriz_sudoku, c)
        for num in col:
            if col.count(num) > 1:
                return False
    return True


sudoku = [
    [5, 3, 4, 6, 7, 8, 9, 1, 2],
    [6, 7, 2, 1, 9, 5, 3, 4, 8],
    [1, 9, 8, 3, 4, 2, 5, 6, 7],
    [8, 5, 9, 7, 6, 1, 4, 2, 3],
    [4, 2, 6, 8, 5, 3, 7, 9, 1],
    [7, 1, 3, 9, 2, 4, 8, 5, 6],
    [9, 6, 1, 5, 3, 7, 2, 8, 4],
    [2, 8, 7, 4, 1, 9, 6, 3, 5],
    [3, 4, 5, 2, 8, 6, 1, 7, 9]
]

print(sudou_valido(sudoku))
