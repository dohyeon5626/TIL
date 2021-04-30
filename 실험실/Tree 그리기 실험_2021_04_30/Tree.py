import turtle as t


def f(angle, count, distance):
    if count == 0:
        return

    percent = 1.3

    t.left(angle / percent)
    t.forward(distance)
    f(angle / percent, count - 1, distance * 2 / 3)
    t.back(distance)
    t.right(angle / percent)

    t.right(angle / percent)
    t.forward(distance)
    f(angle / percent, count - 1, distance * 2 / 3)
    t.back(distance)
    t.left(angle / percent)

    return


t.speed(3000)
t.pensize(2)
t.left(90)
t.penup()
t.back(200)
t.down()
t.forward(100)
f(90, 10, 120)
t.mainloop()
