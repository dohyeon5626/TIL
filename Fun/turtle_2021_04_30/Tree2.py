import turtle as t


def f(count, distance, turn):
    if count == 0:
        return
    length = 450 / turn

    t.left(90)
    t.forward(length)
    t.right(90)
    t.forward(distance)
    f(count - 1, distance, turn * 2)
    t.back(distance)
    t.left(90)
    t.back(length)
    t.right(90)

    t.right(90)
    t.forward(length)
    t.left(90)
    t.forward(distance)
    f(count - 1, distance, turn * 2)
    t.back(distance)
    t.right(90)
    t.back(length)
    t.left(90)

    return


def draw(count, turn):
    f(count, 600 / count, turn)


a = 5  # 단계

t.speed(100)
t.pensize(1)
t.left(90)
t.penup()
t.back(300)
t.down()

draw(a, 2)
t.mainloop()
