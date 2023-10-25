import tkinter
import RandomCGen
gui = tkinter.Tk()
gui.title("Malware Generator")

def sendprompt(): 
    input = insertinp.get("1.0",'end-1c') #1.0 refers to the first line character zero (line.character), end-1c means read to end of text then remove unwanted newline char
    if input != "":
        RandomCGen.gencode(int(input), "")

frame = tkinter.Frame(gui, width=800,height=500)
frame.pack_propagate(0)
frame.pack()
insertlab = tkinter.Label(frame,text="Enter number of generated files:")
insertlab.config(font=("Courier", 8))
insertlab.place(x=5,y=100)
insertinp = tkinter.Text(frame, height= 1, width=20)
insertinp.place(x=10, y=120)
button = tkinter.Button(frame, text = "Generate!",width = 25, command=sendprompt)
button.place(x=300,y= 480)




gui.mainloop()