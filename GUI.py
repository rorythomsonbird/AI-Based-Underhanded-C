import tkinter
import RandomCGen
import MalGen
import os
from tkinter.messagebox import showinfo
from tkinter.messagebox import showerror

class GUI:
    
    

    @classmethod
    def sendprompt(cls,randomgen,insertnuminp,inserttypeinp): 
        inputnum = insertnuminp.get("1.0",'end-1c') #1.0 refers to the first line character zero (line.character), end-1c means read to end of text then remove unwanted newline char
        inputtype = inserttypeinp.get("1.0",'end-1c')
        goodinp = False
        
        
        try:
            number = int(inputnum)
            goodinp = True
        except Exception:
            showerror("Warning", "Please enter a valid number of generated files")
        if inputnum == "":
            goodinp =False
        if goodinp == True:
        
            showinfo("Info", "Generating code... \nPress OK and wait for next popup")
        
            randomgen.gencode(number, inputtype)
            showinfo("Info", "Code generated!")
    
    @classmethod
    def malboy(cls, workbox,malinp):
        prompt = malinp.get("1.0",'end-1c')
        workitems = []
        workbox.selection_set(0, "end")
        for i in workbox.curselection():
            workitems.append(workbox.get(i))
        MalGen.MalGen.malboy(workitems,prompt)
        
    @classmethod
    def compile(cls,randomgen,listbox):
        for i in listbox.curselection():
            showinfo("Info", "Compiling "+listbox.get(i)+"...")
            if randomgen.compilecode("Samples/"+listbox.get(i)) == 1:
                showinfo("Info", "Compiled!")
            else:
                showerror("Warning", "Could not compile. please compile manually.")

    @classmethod
    def initialize(cls):
        
        cls.gui = tkinter.Tk()
        cls.gui.title("Malware Generator")

    @classmethod
    def read(cls,randomgen,listbox):
        for i in listbox.curselection():
            readfile = open("Samples/"+listbox.get(i))

            popup = tkinter.Toplevel()
            popup.wm_title(listbox.get(i))
            code = tkinter.Label(popup, text=readfile.read())
            code.grid(row=0, column=0)
            donebutton = tkinter.Button(popup,text="Done",command=lambda:popup.destroy())
            donebutton.grid(row=5,column=0)
            debugbutton = tkinter.Button(popup,text="Debug",command=lambda:randomgen.debug(listbox.get(i)))
            debugbutton.grid(row=4,column=0)

            readfile.close()

    
    
    @classmethod
    def refreshlist(cls,randomgen,listbox,files,allfiles):
        
        files.clear()
        if allfiles == 1:
            for path in os.listdir("Samples"): 
                files.append(path)
        else:
            files = RandomCGen.genfiles
        listbox.delete(0,tkinter.END)
        
        print(RandomCGen.genfiles)
        for item in files:
            listbox.insert(tkinter.END,item)
    @classmethod
    def allset(cls,randomgen,listbox,files,allfiles):
        allfiles = 1
        cls.refreshlist(randomgen,listbox,files,allfiles)
    @classmethod
    def newset(cls,randomgen,listbox,files,allfiles):
        allfiles = 0
        cls.refreshlist(randomgen,listbox,files,allfiles)

    @classmethod
    def transfer(cls,malbox,listbox):
        for i in listbox.curselection():
            filename = listbox.get(i)
            malbox.insert(tkinter.END,filename)

    @classmethod
    def add(cls,malbox,workbox):
        for i in malbox.curselection():
            filename = malbox.get(i)
            workbox.insert(tkinter.END,filename)
            malbox.delete(malbox.get(0, tkinter.END).index(filename))
    

    @classmethod
    def run(cls):
        cls.initialize()
        randomgen = RandomCGen.RandomCGen()
        frame = tkinter.Frame(cls.gui, width=800,height=500)
        frame.pack_propagate(0)
        frame.pack()
        canvas = tkinter.Canvas(frame, width=800,height=500)
        canvas.create_line(400, 0, 400, 500, width=5)
        canvas.pack()
        #input number of generated files
        insertnumlab = tkinter.Label(frame,text="Enter number of generated files:") 
        insertnumlab.config(font=("Sans", 8))
        insertnumlab.place(x=5,y=100)
        insertnuminp = tkinter.Text(frame, height= 1, width=20)
        insertnuminp.place(x=10, y=120)

        #input type of malicious files
        inserttypelab = tkinter.Label(frame,text="Enter type of generated files:")
        inserttypelab.config(font=("Sans", 8))
        inserttypelab.place(x=5,y=140)
        inserttypeinp = tkinter.Text(frame, height= 1, width=20)
        inserttypeinp.place(x=10, y=160)

        #titles for each section
        nonmallab = tkinter.Label(frame, text = "Generate code!")
        nonmallab.config(font=("Sans", 20))
        nonmallab.place(x=90,y=20)
        mallab = tkinter.Label(frame, text="Make it malicious!")
        mallab.place(x=480,y=20)
        mallab.config(font=("Sans", 20))

        #gencode button
        genbutton = tkinter.Button(frame, text = "Generate!",width = 10, command=lambda:cls.sendprompt(randomgen,insertnuminp,inserttypeinp))
        genbutton.place(x=250,y= 160)

        #list storing files
        allfiles = 0 #sets if all files shown or just newly generated 

        genfiles = list()
        files = list()
        listbox = tkinter.Listbox(frame, height= 10,listvariable=files)
        listbox.place(x=50, y= 220)

        cls.refreshlist(randomgen,listbox,files,allfiles)

        #refresh file list button
        refbutton = tkinter.Button(frame, text = "Refresh",width = 16, command=lambda: cls.refreshlist(randomgen,listbox,files,allfiles))
        refbutton.place(x=50,y= 385)

        #all files button
        allfbutton = tkinter.Button(frame, text = "All",width = 6, command=lambda: cls.allset(randomgen,listbox,files,allfiles))
        allfbutton.place(x=120,y= 195)

        #new files button
        newfbutton = tkinter.Button(frame, text = "New",width = 6, command=lambda: cls.newset(randomgen,listbox,files,allfiles))
        newfbutton.place(x=50,y= 195)
        listboxlab = tkinter.Label(frame, text = "default new")
        listboxlab.config(font=("Sans", 7))
        listboxlab.place(x=180,y=210)

        #compile button
        compilebutton = tkinter.Button(frame, text = "Compile!",width = 10,command=lambda:cls.compile(randomgen,listbox))
        compilebutton.place(x=250,y= 385)

        #read file button
        readbutton = tkinter.Button(frame, text = "Read file",width = 10,command=lambda:cls.read(randomgen,listbox))
        readbutton.place(x=250,y= 360)

        

        #malware listbox
        malbox = tkinter.Listbox(frame, height= 10,listvariable=files)
        malbox.place(x=450, y= 90)
        malboxlab = tkinter.Label(frame, text="Malicious Pending")
        malboxlab.place(x=450,y=70)
        malboxlab.config(font=("Sans", 8))

        #Workplace listbox
        workbox = tkinter.Listbox(frame, height= 10,listvariable=files)
        workbox.place(x=615, y= 90)
        workboxlab = tkinter.Label(frame, text="Work Area")
        workboxlab.place(x=615,y=70)
        workboxlab.config(font=("Sans", 8))

        #transfer file button
        transbutton = tkinter.Button(frame, text = "Make malicious",width = 15,command=lambda:cls.transfer(malbox,listbox))
        transbutton.place(x=250,y= 411)

        #add file button
        addbutton = tkinter.Button(frame, text = "->",width = 5,command=lambda:cls.add(malbox,workbox))
        addbutton.place(x=572,y= 150)

        #remove file button
        rembutton = tkinter.Button(frame, text = "<-",width = 5,command=lambda:cls.add(workbox,malbox))
        rembutton.place(x=572,y= 175)

        #underhanded task input box
        mallab = tkinter.Label(frame,text="Malicious task:") 
        mallab.config(font=("Sans", 8)) 
        mallab.place(x=450,y=270)
        malinp = tkinter.Text(frame, height= 1, width=25)
        malinp.place(x=535, y=270)

        #malboy button
        mbbutton = tkinter.Button(frame, text = "MalBoy",width = 10,command=lambda:cls.malboy(workbox,malinp))
        mbbutton.place(x=450,y= 300)

        #finished file listbox
        workbox = tkinter.Listbox(frame, height= 6,listvariable=files)
        workbox.place(x=450, y= 340)

        cls.gui.mainloop()

    



if __name__ == "__main__":
    GUI.run()