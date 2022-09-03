
class Guerreiros:
    def __init__(self, nome, defesa, forca, energia):
        self.nome = nome
        self.energia = energia
        self.defesa = defesa
        self.forca = forca

    def atacar(self, gato_atacado):
        gato_atacado.defender(self.forca)

    def defender(self, ataque):
        if ataque > self.defesa:
            dano = ataque - self.defesa
            self.energia = self.energia - dano if self.energia - dano >= 0 else 0


lista_de_gatos = []

atacante = Guerreiros(**eval(input()))
N = int(input())
for i in range(N):
    lista_de_gatos.append(Guerreiros(**eval(input())))

print(f'{atacante.nome} esta atacando!')
for cat in lista_de_gatos:
    atacante.atacar(cat)
    print(f'Energia de {cat.nome}: {cat.energia}')
    if cat.energia == 0:
        print(f'{cat.nome} fugiu!')
