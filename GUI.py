import tkinter
from tkinter import ttk
import RandomCGen
import MalGen
from MalwareCheck import MalwareCheck
import os
from tkinter.messagebox import showinfo
from tkinter.messagebox import showerror
from tkinter import simpledialog
titlecolour = '#800000'
buttoncolour = '#ab3b3b'
framecolour = '#ebc6c6'
menucolour = '#f2d9d9' 
class GUI:
    
    
    

    @classmethod
    def sendprompt(cls,randomgen,insertnuminp,inserttypeinp,listbox,files,allfiles): 
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
            cls.newset(randomgen,listbox,files,allfiles)
    
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
            
            tempreplies = []
            for i in range (1,len(replies)):
                if "```" in replies[i]:
                    codemade = True
                    tempreplies.append(replies[i])
            showinfo("MalBoy Success Rate","Success rate: "+str(len(tempreplies))+" of "+str(len(replies)-1)+"\n"+str((len(tempreplies)/(len(replies)-1))*100)+"% success")
            if codemade == True:
                return tempreplies
            else:
                return ""                
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
                return reply
            else:
                reply = reply.replace("Code:","Code:\n```c")
                reply = reply.replace("Directions:","```\ncDirections:")
                return reply                                                            
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
        result = tkinter.Label(popup,bg=framecolour,text=malcheck)
        result.grid(row=0, column=0)
        popup.update()
        detailbutton.destroy()

    @classmethod
    def check(cls,listbox):
        for i in listbox.curselection():
            popuptk = tkinter.Toplevel()
            popup = tkinter.Frame(popuptk,height=300,width=300,bg=framecolour)
            popup.pack()
            popuptk.wm_title("Result")
            malcheck = MalwareCheck.check("Samples/"+listbox.get(i))
            if "Yes" in malcheck:
                checkword = "Malicious intent detected.\nFail."
            else:
                checkword = "No malicious intent detected.\nSuccess!"
                
            result = tkinter.Label(popup, bg=framecolour,width=30,height=10, text=checkword)
            result.grid(row=0, column=0)
            donebutton = tkinter.Button(popup,text="Done",bg=buttoncolour,command=lambda:popuptk.destroy())
            donebutton.grid(row=5,column=0)
            detailbutton = tkinter.Button(popup,text="Detail",bg=buttoncolour,command=lambda:cls.detail(popup,result,malcheck,detailbutton))
            detailbutton.grid(row=4,column=0)

    @classmethod
    def go(cls,finbox,malbox,malinp,checkdevint,checkmalint,curr_mal):
        curr_mal = curr_mal.get()
        checkdevint = checkdevint.get()
        checkmalint = checkmalint.get()
        curr_mal = str.lower(curr_mal)
        if curr_mal == "directory encryption":
            curr_mal = "direncer"
        if curr_mal == "none":
            curr_mal = ""
        if checkdevint == 1 and checkmalint == 1:
            showerror("Warning", "Please only select a maximum of one LLM")
        elif checkdevint == 0 and checkmalint == 1:
            replies = cls.malboy(finbox, malbox, malinp)
            lastreply = replies[len(replies)-1].split("```")
            if replies == "":
                showerror("Fail", "Failure to complete. \nTry again - may require change of wording.")
            else:
                if curr_mal == "":
                    data = "```c"+lastreply[1]+"```"
                else:
                    data = MalGen.MalGen.malinj(curr_mal,lastreply[1][1:])
                    data = "```c"+data+"```"
                cls.createfile(["x",data],finbox)
                showinfo("Code information", lastreply[2])
        elif checkdevint == 1 and checkmalint == 0:
            reply = cls.devilinci(finbox, malbox, malinp)
            if reply == "":
                showerror("Fail", "Failure to complete. \nTry again - may require change of wording.")
            else:
                replysplit = reply.split("```")
                if curr_mal == "":
                    data = replysplit[1]
                    data = "```"+data+"```"
                else:
                    data = MalGen.MalGen.malinj(curr_mal,replysplit[1][1:])
                    data = "```c"+data+"```"
                cls.createfile(["x",data],finbox)
                
                showinfo("Code information", replysplit[2])
                
        else:
            malitems = []
            malbox.selection_set(0, "end")
            for i in malbox.curselection():
                malitems.append(malbox.get(i))
            for file in malitems:
                filestr = MalGen.MalGen.filetostring("Samples/"+file)
                data = MalGen.MalGen.malinj(curr_mal,filestr)
                cls.createfile(["x","```c"+data+"```"],finbox)
            
    @classmethod     
    def createfile(cls,data,finbox):
        genfilename = simpledialog.askstring(title="Name File",prompt="Enter name of new file:")
        MalGen.MalGen.savefile(data,genfilename)
        finbox.insert(tkinter.END,genfilename+".c")
        showinfo("File Status", genfilename+" saved!")

    @classmethod
    def initialize(cls):
        
        cls.gui = tkinter.Tk()
        cls.gui.title("Malware Generator")
        cls.gui.resizable(False, False)

    @classmethod
    def read(cls,randomgen,debug,listbox):
        for i in listbox.curselection():
            readfile = open("Samples/"+listbox.get(i))

            popup = tkinter.Tk()
            readframe = tkinter.Frame(popup, bg=framecolour,width=350,height=500)
            readframe.pack()
            popup.wm_title(listbox.get(i))
            text = tkinter.Text(readframe,bg=menucolour,height=40,width=75,font=(9))
            text.grid(row=0, column=0)
            text.insert(tkinter.END,readfile.read())
            
            scrollbar = tkinter.Scrollbar(readframe,bg=menucolour,orient=tkinter.VERTICAL)
            scrollbar.grid(row=0, column=1, sticky=tkinter.NS)
            text.config(yscrollcommand=scrollbar.set)
            scrollbar.config(command=text.yview)
            donebutton = tkinter.Button(readframe,text="Done",bg=buttoncolour,command=lambda:popup.destroy())
            donebutton.grid(row=6,column=0)
            savebutton = tkinter.Button(readframe,text="Save",bg=buttoncolour,command=lambda:cls.saveread(text,listbox.get(i)))
            savebutton.grid(row=4,column=0)
            if debug ==True:
                debugbutton = tkinter.Button(readframe,text="Debug",bg=buttoncolour,command=lambda:cls.debug(text,randomgen,listbox.get(i),readfile.read()))
                debugbutton.grid(row=5,column=0)
            

            popup.mainloop()
    
    @classmethod
    def saveread(cls,text,file):
        filesave = open("Samples/"+file,"w")
        filesave.write(text.get("1.0",'end-1c'))
        filesave.close()
        showinfo("Save","Changes saved!")

    @classmethod
    def debug(cls,text,randomgen,file,curr):
        showinfo("Debug","Debugging... Please click ok to continue")
        try:
            debugged = randomgen.debug(file)
        except Exception:
            showerror("Error","Could not connect to GPTAPI, please check your connection and")
        newdebfile = open("Samples/"+file,"w")
        newdebfile.write(debugged)
        text.delete('1.0',tkinter.END)
        text.insert(tkinter.END,debugged)
        newdebfile.close()
        if curr == debugged:
            showinfo("Debug status","Everything looks compilable! \nDebug unnecessary")
        else:
            showinfo("Debug status","Code debugged.")

    
    
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
    def rem(cls,malbox):
        for i in malbox.curselection():
            filename = malbox.get(i)
            malbox.delete(malbox.get(0, tkinter.END).index(filename))

    @classmethod
    def help(cls):
        helpscreen = tkinter.Tk()
        helpframe = tkinter.Frame(helpscreen, bg=framecolour,width=500,height=500)
        helpframe.pack()
        helpscreen.wm_title("Help")

        canvas = tkinter.Canvas(helpframe, bg=framecolour,width=420, height=500,borderwidth=30)
        canvas.pack(side=tkinter.LEFT, fill=tkinter.BOTH, expand=True,ipadx=15, ipady=15)
        helptitle = tkinter.Label(canvas, anchor="w",bg=framecolour,height=2,width=20,text = "Instructions")
        helptitle.config(font=("Sans", 20))
        helptitle.place(x=120,y=10)
        
        scrollbar = tkinter.Scrollbar(helpframe, bg=menucolour,command=canvas.yview)
        scrollbar.pack(side=tkinter.LEFT, fill=tkinter.Y)

        helpinfo = MalGen.MalGen.filetostring("Help.txt")
        helptext = tkinter.Label(canvas, bg=framecolour,text = helpinfo,width=300)
        helptext.config(justify="left",anchor="w",font=("Sans", 10))
        helptext.place(x=40,y=70)
        canvas.create_window(0, 0, window=helptitle, anchor=tkinter.NW)
        canvas.create_window(0, 70, window=helptext, anchor=tkinter.NW)

        canvas.config(yscrollcommand=scrollbar.set)
        
        canvas.config(scrollregion=canvas.bbox("all"))
        
    

    @classmethod
    def run(cls):
        cls.initialize()
        randomgen = RandomCGen.RandomCGen()
        frame = tkinter.Frame(cls.gui, bg=framecolour,width=800,height=500)
        frame.pack_propagate(0)
        frame.pack()
        canvas = tkinter.Canvas(frame, bg=framecolour,width=800,height=500)
        canvas.create_line(400, 0, 400, 500, width=2) #Create divider for the two separate GUI sides
        canvas.pack()
        #input number of generated files
        insertnumlab = tkinter.Label(frame,bg=framecolour,text="Enter number of generated files:") 
        insertnumlab.config(font=("Sans", 8))
        insertnumlab.place(x=5,y=100)
        insertnuminp = tkinter.Text(frame, bg=menucolour,height= 1, width=20)
        insertnuminp.place(x=10, y=120)

        #input type of malicious files
        inserttypelab = tkinter.Label(frame,bg=framecolour,text="Enter benign task of generated files:")
        inserttypelab.config(font=("Sans", 8))
        inserttypelab.place(x=5,y=140)
        inserttypeinp = tkinter.Text(frame, bg=menucolour,height= 1, width=20)
        inserttypeinp.place(x=10, y=160)

        #titles for each section
        nonmallab = tkinter.Label(frame, bg=framecolour,text = "Generate code!")
        nonmallab.config(font=("Sans", 20))
        nonmallab.place(x=90,y=20)
        mallab = tkinter.Label(frame, bg=framecolour,text="Make it malicious!")
        mallab.place(x=480,y=20)
        mallab.config(font=("Sans", 20))
        
        #list storing files
        allfiles = 0 #sets if all files shown or just newly generated 
        files = list()
        listbox = tkinter.Listbox(frame, bg=menucolour,height= 10,listvariable=files)
        listbox.place(x=50, y= 220)

        #gencode button
        genbutton = tkinter.Button(frame, text = "Generate!",width = 10,bg = buttoncolour,command=lambda:cls.sendprompt(randomgen,insertnuminp,inserttypeinp,listbox,files,allfiles))
        genbutton.place(x=250,y= 160)

        cls.refreshlist(randomgen,listbox,files,allfiles)

        #refresh file list button
        refbutton = tkinter.Button(frame, text = "Refresh",width = 16, bg = buttoncolour,command=lambda: cls.refreshlist(randomgen,listbox,files,allfiles))
        refbutton.place(x=50,y= 385)

        #all files button
        allfbutton = tkinter.Button(frame, text = "All",width = 6, bg = buttoncolour,command=lambda: cls.allset(randomgen,listbox,files,allfiles))
        allfbutton.place(x=120,y= 195)

        #new files button
        newfbutton = tkinter.Button(frame, text = "New",width = 6, bg = buttoncolour,command=lambda: cls.newset(randomgen,listbox,files,allfiles))
        newfbutton.place(x=50,y= 195)
        listboxlab = tkinter.Label(frame,bg=framecolour, text = "default new")
        listboxlab.config(font=("Sans", 7))
        listboxlab.place(x=180,y=210)

        #compile button
        compilebutton = tkinter.Button(frame, text = "Compile!",width = 10,bg = buttoncolour,command=lambda:cls.compile(randomgen,listbox))
        compilebutton.place(x=250,y= 385)

        #read file button
        readbutton = tkinter.Button(frame, text = "Read file",width = 10,bg = buttoncolour,command=lambda:cls.read(randomgen,True,listbox))
        readbutton.place(x=250,y= 360)

        #malware listbox
        malbox = tkinter.Listbox(frame, bg=menucolour,height= 10,listvariable=files)
        malbox.place(x=420, y= 90)
        malboxlab = tkinter.Label(frame, bg=framecolour, text="Malicious Pending")
        malboxlab.place(x=420,y=70)
        malboxlab.config(font=("Sans", 8))

        #transfer file button
        transbutton = tkinter.Button(frame, text = "Make malicious",width = 15,bg = buttoncolour,command=lambda:cls.transfer(malbox,listbox))
        transbutton.place(x=250,y= 411)

        #remove file button
        rembutton = tkinter.Button(frame, text = "Remove file",width = 16,bg = buttoncolour,command=lambda:cls.rem(malbox))
        rembutton.place(x=420,y= 260)

        #underhanded task input box
        mallab = tkinter.Label(frame,bg=framecolour,text="Malicious task:") 
        mallab.config(font=("Sans", 8)) 
        mallab.place(x=550,y=90)
        malinp = tkinter.Text(frame, bg=menucolour,height= 1, width=25)
        malinp.place(x=550, y=110)

        #finished file listbox
        finbox = tkinter.Listbox(frame, bg=menucolour,height= 6,listvariable=files)
        finbox.place(x=420, y= 340)

        #read finished file button
        readfinbutton = tkinter.Button(frame, text = "Read file",width = 10,bg = buttoncolour,command=lambda:cls.read(randomgen,False,finbox))
        readfinbutton.place(x=615,y= 360)
        
        #compile button
        compilebutton = tkinter.Button(frame, text = "Compile!",width = 10,bg = buttoncolour,command=lambda:cls.compile(randomgen,finbox))
        compilebutton.place(x=615,y= 385)
        
        #MalwareCheck buttons
        mcbutton = tkinter.Button(frame, text = "Malware Check",width = 15,bg = buttoncolour,command=lambda:cls.check(finbox))
        mcbutton.place(x=615,y= 410)    
        mcbutton2 = tkinter.Button(frame, text = "Malware Check",width = 15,bg = buttoncolour,command=lambda:cls.check(listbox))
        mcbutton2.place(x=250,y= 435)

        #malware combobox
        curr_mal = tkinter.StringVar()
        malcombo = ttk.Combobox(frame, textvariable=curr_mal,width = 20) 
        malcombo['values'] = ('None', 'Keylogger', 'Directory Encryption') 
        malcombo.place(x=550,y=160)
        checkmalint = tkinter.IntVar()
        checkdevint = tkinter.IntVar()
        checkmal = tkinter.Checkbutton(frame, text='Malboy',bg=framecolour,variable=checkmalint, onvalue=1, offvalue=0)
        checkdev = tkinter.Checkbutton(frame, text='Devilinci',bg=framecolour,variable=checkdevint, onvalue=1, offvalue=0)
        checkmal.place(x=550,y=130)
        checkdev.place(x=675,y=130)

        #Go button
        gobutton = tkinter.Button(frame,text = "Go!", width = 8, height = 3,bg = buttoncolour,command=lambda:cls.go(finbox,malbox,malinp,checkdevint,checkmalint,curr_mal))
        gobutton.place(x=685,y=200)

        #Help button
        helpbutton = tkinter.Button(frame,text = "Help", width = 8,bg = buttoncolour,command=lambda:cls.help())
        helpbutton.place(x=730,y=5)

        cls.gui.mainloop()

    



if __name__ == "__main__":
    GUI.run()