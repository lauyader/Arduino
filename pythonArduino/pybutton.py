from Tkinter import *

master = Tk()
master.geometry("300x300+0+0")

e = Entry(master)
e.pack()
e.focus_set()
def callback():
    print e.get()
b = Button(master, text="get", width=10, command=callback)
b.grid(row=1,column=1)

b.pack()
mainloop()
