from random import randint
import turtle as t


def f(angle, count, distance):
    if count == 0:
        return

    percent = 1.2

    t.left(angle)
    t.forward(distance)
    f(angle / percent, count - 1, distance * 2 / 3)
    t.back(distance)
    t.right(angle)

    t.right(angle)
    t.forward(distance)
    f(angle / percent, count - 1, distance * 2 / 3)
    t.back(distance)
    t.left(angle)

    return


a = 8 # 단계

t.setup(width = 1000, height = 800)
t.speed(3000)
t.pensize(1)
t.left(90)
t.penup()
t.back(200)
t.down()
t.forward(100)
f(45, a, 120)
t.mainloop()
