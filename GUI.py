import tkinter
import RandomCGen
import os

gui = tkinter.Tk()
gui.title("Malware Generator")

def sendprompt(): 
    inputnum = insertnuminp.get("1.0",'end-1c') #1.0 refers to the first line character zero (line.character), end-1c means read to end of text then remove unwanted newline char
    inputtype = inserttypeinp.get("1.0",'end-1c')
    if inputnum != "":
        RandomCGen.gencode(int(inputnum), inputtype)

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
button = tkinter.Button(frame, text = "Generate!",width = 25, command=sendprompt)
button.place(x=100,y= 480)

#list storing files
allfiles = list()
for path in os.listdir("Samples"): 
        allfiles.append(path)
allfiles = tuple(allfiles)
filelist = tkinter.Variable(value=allfiles)
listbox = tkinter.Listbox(frame, height= 10, listvariable=filelist)
listbox.place(x=50, y= 220)

#refresh file list
button = tkinter.Button(frame, text = "Refresh",width = 16)
button.place(x=50,y= 380)




gui.mainloop()