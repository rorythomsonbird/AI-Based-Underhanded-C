import tkinter
import RandomCGen
import os
from tkinter.messagebox import showinfo

gui = tkinter.Tk()
gui.title("Malware Generator")

def sendprompt(): 
    inputnum = insertnuminp.get("1.0",'end-1c') #1.0 refers to the first line character zero (line.character), end-1c means read to end of text then remove unwanted newline char
    inputtype = inserttypeinp.get("1.0",'end-1c')
    if inputnum != "":
        
        showinfo("Info", "Generating code...")
        
        RandomCGen.gencode(int(inputnum), inputtype)
        showinfo("Info", "Code generated!")
    else:
        showinfo("Warning", "Please enter a number of generated files")

def compile(listbox):
    for i in listbox.curselection():
        RandomCGen.compilecode("Samples/"+listbox.get(i))
    showinfo("Info", "Compiling code...")
    
    showinfo("Info", "Compiled!")

def refreshlist(listbox,files,allfiles):
    files.clear()
    if allfiles == 1:
        for path in os.listdir("Samples"): 
            files.append(path)
    else:
        files = RandomCGen.genfiles
    listbox.delete(0,tkinter.END)
    for item in files:
        listbox.insert(tkinter.END,item)

def allset(listbox,files,allfiles):
    allfiles = 1
    refreshlist(listbox,files,allfiles)

def newset(listbox,files,allfiles):
    allfiles = 0
    refreshlist(listbox,files,allfiles)

frame = tkinter.Frame(gui, width=800,height=500)
frame.pack_propagate(0)
frame.pack()
canvas = tkinter.Canvas(frame, width=800,height=500)
canvas.create_line(400, 0, 400, 500, width=5)
canvas.pack()

#input number of generated files
insertnumlab = tkinter.Label(frame,text="Enter number of generated files:") 
insertnumlab.config(font=("Courier", 8))
insertnumlab.place(x=5,y=100)
insertnuminp = tkinter.Text(frame, height= 1, width=20)
insertnuminp.place(x=10, y=120)

#input type of malicious files
inserttypelab = tkinter.Label(frame,text="Enter type of generated files:")
inserttypelab.config(font=("Courier", 8))
inserttypelab.place(x=5,y=140)
inserttypeinp = tkinter.Text(frame, height= 1, width=20)
inserttypeinp.place(x=10, y=160)

#titles for each section
nonmallab = tkinter.Label(frame, text = "Generate code!")
nonmallab.config(font=("Courier", 20))
nonmallab.place(x=80,y=20)
mallab = tkinter.Label(frame, text="Make it malicious!")
mallab.place(x=460,y=20)
mallab.config(font=("Courier", 20))

#gencode button
genbutton = tkinter.Button(frame, text = "Generate!",width = 10, command=sendprompt)
genbutton.place(x=250,y= 160)

#list storing files
allfiles = 0 #sets if all files shown or just newly generated 

genfiles = list()
files = list()
listbox = tkinter.Listbox(frame, height= 10,listvariable=files)
listbox.place(x=50, y= 220)

refreshlist(listbox,files,allfiles)

#refresh file list button
refbutton = tkinter.Button(frame, text = "Refresh",width = 16, command=lambda: refreshlist(listbox,files,allfiles))
refbutton.place(x=50,y= 385)

#all files button
allfbutton = tkinter.Button(frame, text = "All",width = 6, command=lambda: allset(listbox,files,allfiles))
allfbutton.place(x=120,y= 195)

#new files button
newfbutton = tkinter.Button(frame, text = "New",width = 6, command=lambda: newset(listbox,files,allfiles))
newfbutton.place(x=50,y= 195)

#compile button
compilebutton = tkinter.Button(frame, text = "Compile!",width = 10,command=lambda:compile(listbox))
compilebutton.place(x=250,y= 385)




gui.mainloop()