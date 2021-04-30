import turtle as t
import random


def draw():
    t.forward(10)
    t.right(90)
    t.forward(2)
    t.right(90)
    t.forward(10)
    t.left(90)
    t.forward(2)
    t.left(90)


def gameStartDrawOnce():
    t.forward(80)
    t.left(90)
    t.forward(15)
    t.left(90)


def gameStartDraw():
    gameStartDrawOnce()
    gameStartDrawOnce()


def randomCircle():
    t.penup()
    t.goto(random.randrange(-300, 300), random.randrange(-300, 300))
    t.pendown()
    t.circle(random.randrange(20, 50))


t.hideturtle()
t.speed(3000)
t.pensize(2)

t.penup()
t.back(40)
t.pendown()
t.write("loading..")
t.penup()
t.forward(10)
t.right(90)
t.forward(30)
t.left(90)
t.back(300)
t.left(90)
t.pendown()


for i in range(0, 50):
    t.speed(random.randrange(1, 2000))
    draw()
for i in range(0, 30):
    t.speed(random.randrange(1, 100))
    draw()
for i in range(0, 70):
    t.speed(random.randrange(300, 2000))
    draw()
t.clear()
t.penup()
t.home()
t.back(100)
t.pendown()
t.write("GAME START", font=("맑은고딕", 18, "bold"))
t.speed(1)
for i in range(30):
    randomCircle()
t.mainloop()
