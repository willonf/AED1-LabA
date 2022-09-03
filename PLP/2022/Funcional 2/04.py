from functools import reduce

sum = 0
a = int(input())
w = int(input())

sum = lambda x, y: x + y

print(reduce(sum, range(a, w+1)))

