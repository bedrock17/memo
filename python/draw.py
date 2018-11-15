import tkinter
import math

# 벡터를 이용한 도형그리기

def get_pos(x1, y1, x2, y2, l, o):
    rx, ry = 0, 0
    
    x2_x1 = x2-x1
    y1_y2 = y1-y2

    rx = (x2+x1)/2 +((l * y1_y2) / math.sqrt(y1_y2**2 + x2_x1**2))*o
    ry = (y1+y2)/2 +((l * x2_x1) / math.sqrt(y1_y2**2 + x2_x1**2))*o

    return rx, ry

x1, y1, x2, y2 = 100, 100, 200, 200
window = tkinter.Tk()
canva = tkinter.Canvas(window)

x3, y3 = get_pos(x1, y1, x2, y2, 50, 1)
canva.create_line(x2, y2, x3, y3)
canva.create_line(x1, y1, x3, y3)

x3, y3 = get_pos(x1, y1, x2, y2, 50, -1)
canva.create_line(x2, y2, x3, y3)
canva.create_line(x1, y1, x3, y3)

line = canva.create_line(x1, y1, x2, y2)

canva.pack()

window.mainloop()

# from tkinter import Tk, Label, Button

# class MyFirstGUI:
#     def __init__(self, master):
#         self.master = master
#         master.title("A simple GUI")

#         self.label = Label(master, text="This is our first GUI!")
#         self.label.pack()

#         self.greet_button = Button(master, text="Greet", command=self.greet)
#         self.greet_button.pack()

#         self.close_button = Button(master, text="Close", command=master.quit)
#         self.close_button.pack()

#     def greet(self):
#         print("Greetings!")

# root = Tk()
# my_gui = MyFirstGUI(root)
# root.mainloop()