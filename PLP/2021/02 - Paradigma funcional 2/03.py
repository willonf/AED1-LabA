def fatorial(n):
    if n == 1:
        return 1
    else:
        return fatorial(n-1) * n


fatoriais = []
result = []
caso = eval(input())
bigger = max(caso)
cond = True

for i in range(1, bigger):
    fat = fatorial(i)
    fatoriais.append(fat)
    if fat == bigger:
        break

for number in caso:
    if number in fatoriais:
        result.append(number)
print(result)
