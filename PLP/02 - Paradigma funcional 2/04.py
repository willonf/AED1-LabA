def f(b, e):
    if e == 1:
        return b
    elif e == 0:
        return 1
    elif e % 2 == 0:
        return f(b, e / 2) * f(b, e / 2)
    else:
        return b * f(b, e - 1)


qtde = int(input())
for i in range(qtde):
    case = eval(input())
    if case[1] < 0:
        break
    print(f(case[0], case[1]))
