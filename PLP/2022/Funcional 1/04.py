def mdc(a, b):
	if a == b:
		return a
	elif a > b:
		return mdc(a-b, b)
	elif b > a:
		return mdc(a, b-a)
	

if __name__ == '__main__':
	a = int(input())
	b = int(input())
	print(mdc(a, b))