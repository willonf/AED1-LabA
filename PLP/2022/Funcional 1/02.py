def bigger(my_list, length, index):
	if length == 0:
		return my_list[index]
	elif my_list[length - 1] > my_list[index]:
		return bigger(my_list, length - 1, length - 1)
	else:
		return bigger(my_list, length - 1, index)

N = int(input())

lista = eval(input())

print(bigger(lista, len(lista), 0))