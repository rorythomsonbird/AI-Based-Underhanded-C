import tkinter
from tkinter import ttk
import RandomCGen
import MalGen
from MalwareCheck import MalwareCheck
import os
from tkinter.messagebox import showinfo
from tkinter.messagebox import showerror
from tkinter import simpledialog

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
    def malboy(cls, finbox, workbox,malinp):
        prompt = malinp.get("1.0",'end-1c')
        workitems = []
        workbox.selection_set(0, "end")
        for i in workbox.curselection():
            workitems.append(workbox.get(i))
        try:
            replies = MalGen.MalGen.malboy(workitems,prompt)
            codemade = False
            codecount = 0
            for i in range (1,len(replies)):
                if "```" in replies[i]:
                    codemade = True
                    codecount +=1
            showinfo("Success Rate","Success rate: "+str(codecount)+" of "+str(len(replies)-1)+"\n"+str((codecount/(len(replies)-1))*100)+"% success")
            if codemade == True:
                genfilename = simpledialog.askstring(title="Name File",prompt="Enter name of new file:")
                MalGen.MalGen.savefile(replies,genfilename)
                finbox.insert(tkinter.END,genfilename+".c")
                lastreply = replies[len(replies)-1].split("```")
                showinfo("Code information", lastreply[2])
            else:
                showerror("Fail", "Failure to complete. \nTry again - may require change of wording.")
        except Exception:
            showerror("Error communicating","Error communicating with LLM.\nPlease ensure a valid internet connection.")

    
    @classmethod
    def devilinci(cls, finbox, workbox,malinp):
        prompt = malinp.get("1.0",'end-1c')
        workitems = []
        workbox.selection_set(0, "end")
        for i in workbox.curselection():
            workitems.append(workbox.get(i))
        try:
            reply = MalGen.MalGen.devilinci(workitems,prompt)
         
            if "```" in reply:
                genfilename = simpledialog.askstring(title="Name File",prompt="Enter name of new file:")
                MalGen.MalGen.savefile(["x",reply],genfilename)#array with x in sent to be compatible with savefile
                finbox.insert(tkinter.END,genfilename+".c")
                replysplit = reply.split("```")
                showinfo("Code information", replysplit[2])
            
        except Exception:
            showerror("Error communicating","Error communicating with LLM.\nPlease ensure a valid internet connection.")
    @classmethod
    def compile(cls,randomgen,listbox):
        for i in listbox.curselection():
            showinfo("Info", "Compiling "+listbox.get(i)+"...")
            if randomgen.compilecode("Samples/"+listbox.get(i)) == 1:
                showinfo("Info", "Compiled!")
            else:
                showerror("Warning", "Could not compile. please compile manually.")
    
    @classmethod
    def detail(cls,popup,result,malcheck,detailbutton):
        result.destroy()
        detailbutton.destroy()
        result = tkinter.Label(popup, text=malcheck)
        result.grid(row=0, column=0)
        detailbutton.destroy()

    @classmethod
    def check(cls,listbox):
        for i in listbox.curselection():
            popup = tkinter.Toplevel()
            popup.wm_title("Result")
            malcheck = MalwareCheck.check("Samples/"+listbox.get(i))
            if "Yes" in malcheck:
                checkword = "Malicious intent detected.\nFail."
            else:
                checkword = "No malicious intent detected.\nSuccess!"
                
            result = tkinter.Label(popup, text=checkword)
            result.grid(row=0, column=0)
            donebutton = tkinter.Button(popup,text="Done",command=lambda:popup.destroy())
            donebutton.grid(row=5,column=0)
            detailbutton = tkinter.Button(popup,text="Detail",command=lambda:cls.detail(popup,result,malcheck,detailbutton))
            detailbutton.grid(row=4,column=0)

    @classmethod
    def go(cls,finbox,malbox,malinp,checkdevint,checkmalint,malcombo):
        if checkdevint == 1 and checkmalint == 1:
            showerror("Warning", "Please only select a maximum of one LLM")
        elif checkdevint == 0 and checkmalint == 1:
            cls.malboy(finbox, malbox, malinp)
            if malcombo



    @classmethod
    def initialize(cls):
        
        cls.gui = tkinter.Tk()
        cls.gui.title("Malware Generator")

    @classmethod
    def read(cls,randomgen,debug,listbox):
        for i in listbox.curselection():
            readfile = open("Samples/"+listbox.get(i))

            popup = tkinter.Toplevel()
            popup.wm_title(listbox.get(i))
            code = tkinter.Label(popup, text=readfile.read())
            code.grid(row=0, column=0)
            donebutton = tkinter.Button(popup,text="Done",command=lambda:popup.destroy())
            donebutton.grid(row=5,column=0)
            if debug ==True:
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
        readbutton = tkinter.Button(frame, text = "Read file",width = 10,command=lambda:cls.read(randomgen,True,listbox))
        readbutton.place(x=250,y= 360)

        

        #malware listbox
        malbox = tkinter.Listbox(frame, height= 10,listvariable=files)
        malbox.place(x=420, y= 90)
        malboxlab = tkinter.Label(frame, text="Malicious Pending")
        malboxlab.place(x=420,y=70)
        malboxlab.config(font=("Sans", 8))


        #transfer file button
        transbutton = tkinter.Button(frame, text = "Make malicious",width = 15,command=lambda:cls.transfer(malbox,listbox))
        transbutton.place(x=250,y= 411)


        #remove file button
        rembutton = tkinter.Button(frame, text = "Remove file",width = 16,command=lambda:cls.add(malbox,listbox))
        rembutton.place(x=420,y= 260)

        #underhanded task input box
        mallab = tkinter.Label(frame,text="Malicious task:") 
        mallab.config(font=("Sans", 8)) 
        mallab.place(x=550,y=90)
        malinp = tkinter.Text(frame, height= 1, width=25)
        malinp.place(x=550, y=110)

        #finished file listbox
        finbox = tkinter.Listbox(frame, height= 6,listvariable=files)
        finbox.place(x=420, y= 340)

        #malboy button
        mbbutton = tkinter.Button(frame, text = "MalBoy",width = 10,command=lambda:cls.malboy(finbox,malbox,malinp))
        mbbutton.place(x=550,y= 130)

        #devilinci button
        mbbutton = tkinter.Button(frame, text = "Devilinci",width = 10,command=lambda:cls.devilinci(finbox,malbox,malinp))
        mbbutton.place(x=675,y= 130)

        #read finished file button
        readfinbutton = tkinter.Button(frame, text = "Read file",width = 10,command=lambda:cls.read(randomgen,False,finbox))
        readfinbutton.place(x=615,y= 360)
        
        #compile button
        compilebutton = tkinter.Button(frame, text = "Compile!",width = 10,command=lambda:cls.compile(randomgen,finbox))
        compilebutton.place(x=615,y= 385)
        
        #MalwareCheck button
        mcbutton = tkinter.Button(frame, text = "Malware Check",width = 15,command=lambda:cls.check(finbox))
        mcbutton.place(x=615,y= 410)

        #malware combobox
        malcombo = ttk.Combobox(frame, width = 20) 
        curr_mal = tkinter.StringVar()
        malcombo['values'] = ('None', 'Keylogger', 'Directory Encryption', 'All') 
        malcombo.place(x=550,y=160)

        checkmalint = tkinter.IntVar
        checkdevint = tkinter.IntVar
        checkmal = tkinter.Checkbutton(frame, text='Malboy',variable=checkmalint, onvalue=1, offvalue=0)
        checkdev = tkinter.Checkbutton(frame, text='Devilinci',variable=checkdevint, onvalue=1, offvalue=0)
        checkmal.place(x=550,y=130)
        checkdev.place(x=675,y=130)
        #Go button
        gobutton = tkinter.Button(frame,text = "Go!", width = 8, height = 3,command=lambda:cls.go(finbox,malbox,malinp,checkdevint,checkmalint,malcombo))
        gobutton.place(x=685,y=200)

        cls.gui.mainloop()

    



if __name__ == "__main__":
    GUI.run()