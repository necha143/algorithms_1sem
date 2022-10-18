class Holodos():
    def __init__(self, m, ma, s, v):
        self.moloko = m
        self.myaso = ma
        self.sir = s
        self.vkysnyaha = v

    def vivod(self):
        print("В холодильнике:", "\nЛитров молока: ", self.moloko , "\nКг мяса: ", p1.myaso, "\nКусочков сыра: ", p1.sir,
        "\nКоличество вкусняшек: ", p1.vkysnyaha)

    def molok(self):
        print("Ого, вы купили молока, сколько литров?")
        self.moloko+=int(input())
        print("Теперь в холодильнике", p1.moloko, "литров")

    def vkys(self):
        print("Желаете взять вкусняшек? Сколько?")
        self.vkysnyaha-=int(input())
        print("Вкусняшек осталось:", p1.vkysnyaha)

p1 = Holodos(5, 20, 8, 24)
p1.vivod()
p1.molok()
p1.vkys()