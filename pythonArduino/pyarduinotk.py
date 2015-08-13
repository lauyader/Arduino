from serial import *
from Tkinter import *




#make a TkInter Window
root = Tk()
root.title("Mi primera ventana")

label1 = Label(root,text="Introduccion en TkInter")
label1.grid(row=3,column=3)

Encender13 = Button(root,text="Encender led 13")
Encender13.grid(row=4,column=3)
for x in range(0, 3):
    print "We're on time %d" % (x)
    caja = Entry(root,textvariable = (x))
    caja.grid(row=6,column=3)

Encender10 = Button(root,text="Encender led 10")
Encender10.grid(row=5,column=3)
root.mainloop()
