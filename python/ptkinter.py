from Tkinter import *
import Tkinter
import tkMessageBox
class operaciones:
    global nombre
    global nom

    def registrar(self,nomb,edad,cita):
        f = open("C:/Users/fernando/workspace/probando/src/agendapa.txt", "r+")
        f.write("\n"+nomb)
        f.write("\n"+edad)
        f.write("\n"+cita)
        f.close()
        tkMessageBox.showinfo("Finalizado","Paciente registrado con exito")


    def multiplicar(self):
        pass

    def nuevopaciente(self):
        nuevopac = Toplevel()
        nuevopac.title("Menu para nuevo paciente")
        nuevopac.minsize(500,500)
        frameiz=Frame(nuevopac,width=50,height=100)
        frameiz.pack(side=LEFT, expand=NO, fill=NONE)
        frametop=Frame(frameiz,width=50,height=199)
        frametop.pack(side=TOP)
        L1 = Label(frametop, text="Nombre del paciente")
        L1.pack(side=LEFT,anchor=NW)
        L2 = Label(frametop, text="Edad del paciente")
        L2.pack(side=LEFT,anchor=W)
        L3 = Label(frametop, text="Proxima cita")
        L3.pack(side=LEFT,anchor=SW)
        nombre=Entry(frametop,textvariable="Nombre del paciente")
        edad=Entry(frametop,textvariable="Edad del paciente")
        cita=Entry(frametop,textvariable="Proxima cita")
        nombre.pack(side=TOP,anchor=E)
        edad.pack(side=BOTTOM,anchor=SE)
        cita.pack(side=BOTTOM)
        nom=str(nombre.get())
        ed=str(edad.get())
        cit=str(cita.get())
        botonparamultiplicar=Button(nuevopac,text="Para Registrar",command=ob.registrar(nom,ed,cit)).pack()
        nuevopac.mainloop()


class inicio(operaciones):
    def iniciando(self):
        global ob
        ob = inicio()
        root=Tk()
        root.title("Odontologia Estetica")
        root.maxsize(800,600)
        root.minsize(300,300)
        menu=Menu(root)
        root.config(menu=menu)
        opciones=Menu(menu)
        menu.add_cascade(label="Operaciones",menu=opciones)
        opciones.add_command(label="Nuevo paciente",command=ob.nuevopaciente)
        opciones.add_command(label="Editar paciente")
        opciones.add_command(label="Agenda")
        root.mainloop()

objeto = inicio()
objeto.iniciando()
