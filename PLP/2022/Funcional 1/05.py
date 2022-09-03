def menor(L):
	if len(L) == 1:
		return L[0]
	elif L[0] < L[-1]:
		return menor(L[:-1])
	else:
		return menor(L[1:])

	
if __name__ == "__main__":
	caso = eval(input())
	print(menor(caso))