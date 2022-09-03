def invert_list (my_list):
	if not my_list:
		return my_list
	return my_list[-1:] + invert_list(my_list[:-1])


lista = eval(input())

print(invert_list(lista))




