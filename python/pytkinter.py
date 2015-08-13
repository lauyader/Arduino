import Tkinter, tkMessageBox

def Saludar():

    tkMessageBox.showinfo("Hola", "Hola Mundo!")

ventana = Tkinter.Tk()
boton = Tkinter.Button(ventana,text="Boton", font="algerian", command=Saludar)
boton.grid(padx=50, pady=50)
ventana.mainloop()
