
class Pilha:
    FIRST = 0

    def __init__(self):
        self.pilha = list()

    @property
    def vazia(self):
        return False if len(self.pilha) > 0 else True

    def topo(self, element=None):
        if element is None:
            topo = self.pilha.pop(self.FIRST)
            return topo
        else:
            self.pilha.insert(self.FIRST, element)


expressao = str(input())
pilha = Pilha()


for exp in expressao:
    if exp == '{' or exp == '[' or exp == '(':
        pilha.topo(exp)
    elif exp == '}' or exp == ']' or exp == ')':
        if not pilha.vazia:
            exp2 = str(pilha.topo())
            if (exp == '}' and exp2 != '{') or (exp == ']' and exp2 != '[') or (exp == ')' and exp2 != '('):
                print('nao')
                break
        else:
            print('nao')
if pilha.vazia:
    print('sim')
