import tkinter
from tkinter import ttk
import RandomCGen
import MalGen
from MalwareCheck import MalwareCheck
import os
from tkinter.messagebox import showinfo
from tkinter.messagebox import showerror
from tkinter import simpledialog
buttoncolour = '#6a0622'
framecolour = '#ebc6c6'
menucolour = '#f2d9d9' 
class GUI:
    
    
    

    @classmethod
    def sendprompt(cls,randomgen,insertnuminp,inserttypeinp,listbox,files,allfiles): #Send benign code generation prompt and create new samples
        inputnum = insertnuminp.get("1.0",'end-1c') #1.0 refers to the first line character zero (line.character),
        #end-1c means read to end of text then remove unwanted newline char
        inputtype = inserttypeinp.get("1.0",'end-1c')
        goodinp = False
        
        
        try:
            number = int(inputnum)#Transform into Integer
            goodinp = True
        except Exception:
            showerror("Warning", "Please enter a valid number of generated files")
        if inputnum == "":
            goodinp =False
            showerror("Warning", "Please enter a valid number of generated files")
        if goodinp == True:
        
            showinfo("Info", "Generating code... \nPress OK and wait for next popup")
        
            genfiles = randomgen.gencode(number, inputtype)#Send prompt
            if randomgen.error == 1 or genfiles==[]:#Checks if there was an error in generating the code
                showerror("Code Generation error", "There was an error generating code.\n"+
                          "Please ensure your prompt was benign and try again.")
                randomgen.error = 0
            else:
                showinfo("Info", "Code generated!")
            cls.newset(listbox,files,allfiles)#Set ListBox to show new files
    
    @classmethod
    def malboy(cls, workbox,malinp): #MalBoy function to alter benign code into underhanded code
        prompt = malinp.get("1.0",'end-1c')
        workitems = []
        workbox.selection_set(0, "end")
        for i in workbox.curselection():
            workitems.append(workbox.get(i))#Transform ListBox contents into a List
        try:
            replies = MalGen.MalGen.malboy(workitems,prompt)#Send prompt
            codemade = False
            
            tempreplies = []
            for i in range (1,len(replies)):#Check if code generated
                if "```" in replies[i]:
                    codemade = True
                    tempreplies.append(replies[i])
            showinfo("MalBoy Success Rate","Success rate: "+str(len(tempreplies))+" of "+str(len(replies)-1)
                     +"\n"+str((len(tempreplies)/(len(replies)-1))*100)+"% success")#Calculate success rate
            if codemade == True:
                return tempreplies
            else:
                return ""                
        except Exception:
            showerror("Error communicating","Error communicating with LLM.\nPlease ensure a valid internet connection.")

    
    @classmethod
    def devilinci(cls, workbox,malinp):#Devilinci method of altering benign code into underhanded code
        prompt = malinp.get("1.0",'end-1c')
        workitems = []
        workbox.selection_set(0, "end")
        for i in workbox.curselection():
            workitems.append(workbox.get(i))#Transform ListBox contents into List
        try:
            reply = MalGen.MalGen.devilinci(workitems,prompt)#Send prompt
         
            if "```" in reply:
                return reply
            else:
                reply = reply.replace("Code:","Code:\n```c")#Remove unnecessary headers
                reply = reply.replace("Directions:","```\ncDirections:")
                return reply                                                            
        except Exception:
            showerror("Error communicating","Error communicating with LLM.\nPlease ensure a valid internet connection.")
    @classmethod
    def compile(cls,randomgen,listbox):#Sends code to be compiled
        if listbox.curselection()==():
            showerror("Error","Please select a file.")
        for i in listbox.curselection():
            showinfo("Info", "Compiling "+listbox.get(i)+"...")
            if randomgen.compilecode("Samples/"+listbox.get(i)) == 1:#Compile function called with selected file
                showinfo("Info", "Compiled!")
            else:
                showerror("Warning", "Could not compile. please compile manually.")
    
    @classmethod
    def detail(cls,donebutton,popup,popuptk,result,malcheck,detailbutton):#Transform popup to show more detail, from MalwareCheck popup
        result.destroy()
        detailbutton.destroy()#Destroy irrelevant features of old popup
        donebutton.destroy()
        result = tkinter.Label(popup,wraplength=400,bg=framecolour,text=malcheck)#New label for detail with information as text
        result.pack()
        donebutton = tkinter.Button(popup,text="Done",fg = '#ffffff',bg=buttoncolour,command=lambda:popuptk.destroy())
        donebutton.pack()
        popup.update()
        

    @classmethod
    def check(cls,listbox):#MalwareCheck popup
        if listbox.curselection()==():
            showerror("Error","Please select a file.")
        for i in listbox.curselection():
            popuptk = tkinter.Toplevel()
            popup = tkinter.Frame(popuptk,height=300,width=300,bg=framecolour)#Create popup
            popuptk.resizable(False, False)
            popup.pack()
            popuptk.wm_title("Result")
            malcheck = MalwareCheck.check("Samples/"+listbox.get(i))#Call MalwareCheck
            if "Yes" in malcheck:#Shows relevant information, not full information
                checkword = "Malicious intent detected.\nFail."
            else:
                checkword = "No malicious intent detected.\nSuccess!"
                
            result = tkinter.Label(popup, wraplength=100,bg=framecolour,width=30,height=10, text=checkword)
            result.pack()
            donebutton = tkinter.Button(popup,text="Done",fg = '#ffffff',bg=buttoncolour,command=lambda:popuptk.destroy())
            donebutton.pack()
            detailbutton = tkinter.Button(popup,text="Detail",fg = '#ffffff',bg=buttoncolour,command=
                                          lambda:cls.detail(donebutton,popup,popuptk,result,malcheck,detailbutton))
            detailbutton.pack()

    @classmethod
    def jailbreakmod(cls,malbox,jailbreak,malinp):#Sends jailbreak model use information
        prompt = malinp.get("1.0",'end-1c')#Transform TextBox information to String
        malitems = []
        malbox.selection_set(0, "end")
        for i in malbox.curselection():
            malitems.append(malbox.get(i))#Gets selected filenames
        try:
            reply = MalGen.MalGen.jailbreak(jailbreak, prompt, malitems)[-1] #Send prompt to Jailbreak
            if "```" in reply:#Checks if code
                return reply
            else:
                reply = reply.replace("Code:","Code:\n```c")#Remove headers
                reply = reply.replace("Directions:","```\ncDirections:")
                return reply                                                            
        except Exception:
            showerror("Error communicating","Error communicating with LLM.\nPlease ensure a valid internet connection.")

    @classmethod
    def go(cls,finbox,malbox,malinp,checkdevint,checkmalint,curr_mal,checkjailint,jailbreak):#Container function for selected models
        curr_mal = curr_mal.get()#Transforms information as Strings/Integers
        jailbreak = jailbreak.get()
        checkdevint = checkdevint.get()
        checkmalint = checkmalint.get()
        checkjailint = checkjailint.get()
        curr_mal = str.lower(curr_mal)#Makes all options lowercase for easy lookup
        if curr_mal == "directory encryption":#Check which additional malware has been selected and changes them to correct format
            curr_mal = "direncer"
        if curr_mal == "none":
            curr_mal = ""
        showinfo("Info", "Beginning underhanded activities...\nPress OK and wait.")
        if checkjailint+checkdevint+checkmalint > 1:#Checks if too many CheckBoxes have been selected
            showerror("Warning", "Please only select a maximum of one LLM")
        elif checkmalint == 1:#Checks if MalBoy selected
            replies = cls.malboy(malbox, malinp)#Call MalBoy function
            lastreply = replies[len(replies)-1].split("```")
            if replies == "":#Check for failure
                showerror("Fail", "Failure to complete. \nTry again - may require change of wording.")
            else:
                if curr_mal == "":#Checks what additional malware has been selected
                    data = "```c"+lastreply[1]+"```"
                else:
                    data = MalGen.MalGen.malinj(curr_mal,lastreply[1][1:])#Calls Malware Injection function
                    data = "```c"+data+"```"
                cls.createfile(["x",data],finbox)#Creates new file
                showinfo("Code information", lastreply[2])#Display directions
        elif checkdevint == 1:#Checks if Devilinci selected
            reply = cls.devilinci(malbox, malinp)#Call Devilinci
            if reply == "":#Error check
                showerror("Fail", "Failure to complete. \nTry again - may require change of wording.")
            else:
                replysplit = reply.split("```")#Retrieve code
                if curr_mal == "":
                    try:
                        data = replysplit[1]
                        data = "```"+data+"```"
                    except:
                        showerror("Fail", "Failure to complete. \nTry again - may require change of wording.")
                else:
                    try:
                        data = MalGen.MalGen.malinj(curr_mal,replysplit[1][1:])#Call malware injection
                        data = "```c"+data+"```"
                    except:
                        showerror("Fail", "Failure to complete. \nTry again - may require change of wording.")
                cls.createfile(["x",data],finbox)#Create new file
                if replysplit[2] == "":
                    replysplit[2] = "No instructions."
                showinfo("Code information", replysplit[2])#Display directions
        elif checkjailint==1:#Checks if jailbreak selected
            if jailbreak == "":
                showerror("Fail", "Please select a jailbreak model.")
            else:
                reply = cls.jailbreakmod(malbox,jailbreak,malinp)#Call jailbreak function
                if reply == "":
                    showerror("Fail", "Failure to complete. \nTry again - may require change of wording.")
                else:
                    try:
                        replysplit = reply.split("```")#Checks for code
                        if curr_mal == "":
                            data = replysplit[1]
                            data = "```"+data+"```"
                        else:
                            data = MalGen.MalGen.malinj(curr_mal,replysplit[1][1:])#Calls malware injection
                            data = "```c"+data+"```"
                    
    
                        cls.createfile(["x",data],finbox)#Create file
                        if replysplit[2] == "":
                            replysplit[2] = "No instructions."
                        showinfo("Code information", replysplit[2])#Show instructions
                    except:
                        showerror("Fail", "Failure to complete. \nTry again - may require change of wording.")
        else:
            if curr_mal == "":#Checks if nothing is selected
                showerror("Fail", "Please select an underhanded model or select a malicious snippet to inject.")
            else:
                malitems = []
                malbox.selection_set(0, "end")
                for i in malbox.curselection():#Gets files
                    malitems.append(malbox.get(i))
                for file in malitems:
                    filestr = MalGen.MalGen.filetostring("Samples/"+file)
                    data = MalGen.MalGen.malinj(curr_mal,filestr)#Call malware injection
                    cls.createfile(["x","```c"+data+"```"],finbox)#Create new file
            
    @classmethod     
    def createfile(cls,data,finbox):#Creates a new file
        genfilename = simpledialog.askstring(title="Name File",prompt="Enter name of new file:")#Prompt for name of new file
        MalGen.MalGen.savefile(data,genfilename)#Send data and name to savefile function
        finbox.insert(tkinter.END,genfilename+".c")#Adds to finished ListBox
        showinfo("File Status", genfilename+" saved!")

    @classmethod
    def initialise(cls):#Initialise the GUI
        
        cls.gui = tkinter.Tk()#Make window
        cls.gui.title("Malware Generator")
        cls.gui.resizable(False, False)

    @classmethod
    def read(cls,randomgen,debug,listbox):#Opens text editor
        if listbox.curselection()==():#Checks if a file has been selected
            showerror("Error","Please select a file.")
        for i in listbox.curselection():
            readfile = open("Samples/"+listbox.get(i))#Retrieves data

            popup = tkinter.Tk()#Makes a new window
            popup.geometry("655x793")
            popup.resizable(False, False)
            readframe = tkinter.Frame(popup, bg=framecolour,width=250,height=400)
            readframe.pack(fill=tkinter.BOTH, expand=True)
            popup.wm_title(listbox.get(i))
            text = tkinter.Text(readframe,bg=menucolour,height=31,width=58,font=(5))#Adds relevant widgets
            text.grid(row=0, column=0)
            text.insert(tkinter.END,readfile.read())#Adds data to the editable TextBox
             
            scrollbar = tkinter.Scrollbar(readframe,bg=menucolour,orient=tkinter.VERTICAL)
            scrollbar.grid(row=0, column=1, sticky=tkinter.NS)
            text.config(yscrollcommand=scrollbar.set)
            scrollbar.config(command=text.yview)
            donebutton = tkinter.Button(readframe,text="Done",fg = '#ffffff',bg=buttoncolour,
                                        command=lambda:popup.destroy())
            donebutton.grid(row=6,column=0)
            savebutton = tkinter.Button(readframe,text="Save",fg = '#ffffff',bg=buttoncolour,
                                        command=lambda:cls.saveread(text,listbox.get(i)))
            savebutton.grid(row=4,column=0)
            if debug ==True:
                debugbutton = tkinter.Button(readframe,text="Debug",fg = '#ffffff',bg=buttoncolour,
                                             command=lambda:cls.debug(text,randomgen,listbox.get(i),readfile.read()))
                debugbutton.grid(row=5,column=0)
            

            popup.mainloop()
    
    @classmethod
    def saveread(cls,text,file):#Saves changes in text editor
        filesave = open("Samples/"+file,"w")
        filesave.write(text.get("1.0",'end-1c'))
        filesave.close()
        showinfo("Save","Changes saved!")

    @classmethod
    def debug(cls,text,randomgen,file,curr):#Automatically debugs file
        showinfo("Debug","Debugging... Please click ok to continue")
        try:
            debugged = randomgen.debug(file)#Sends debug the filename to debug
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
    def refreshlist(cls,listbox,files,allfiles):#Refreshes first ListBox
        
        files.clear()
        if allfiles == 1:#Shows all files in directory
            for path in os.listdir("Samples"): 
                files.append(path)
        else:
            files = RandomCGen.genfiles#Shows newly generated files
        listbox.delete(0,tkinter.END)
        for item in files:
            listbox.insert(tkinter.END,item)#Adds file names to ListBox
    @classmethod
    def allset(cls,listbox,files,allfiles):#Set the files in ListBox to entire directory
        allfiles = 1
        cls.refreshlist(listbox,files,allfiles)#Calls ListBox to be refreshed
    @classmethod
    def newset(cls,listbox,files,allfiles):#Set the files in ListBox to newly generated files
        allfiles = 0
        cls.refreshlist(listbox,files,allfiles)#Calls ListBox to be refreshed

    @classmethod
    def transfer(cls,malbox,listbox):#Moves files from ListBox to another ListBox
        if listbox.curselection()==():
            showerror("Error","Please select a file.")
        for i in listbox.curselection():
            filename = listbox.get(i)
            malbox.insert(tkinter.END,filename)

    @classmethod
    def rem(cls,malbox):#Removes files from ListBox
        if malbox.curselection()==():
            showerror("Error","Please select a file.")
        for i in malbox.curselection():
            filename = malbox.get(i)
            malbox.delete(malbox.get(0, tkinter.END).index(filename))

    @classmethod
    def help(cls):#Shows an instructional popup
        helpscreen = tkinter.Tk()#Make new window
        helpscreen.resizable(False, False)
        helpframe = tkinter.Frame(helpscreen, bg=framecolour,width=500,height=500)
        helpframe.pack()
        helpscreen.wm_title("Help")

        canvas = tkinter.Canvas(helpframe, bg=framecolour,width=420, height=500,borderwidth=30)#Insert widgets
        canvas.pack(side=tkinter.LEFT, fill=tkinter.BOTH, expand=True,ipadx=15, ipady=15)
        helptitle = tkinter.Label(canvas, anchor="w",bg=framecolour,height=2,width=20,text = "Instructions")
        helptitle.config(font=("Sans", 20))
        helptitle.place(x=120,y=10)
        
        scrollbar = tkinter.Scrollbar(helpframe, bg=menucolour,command=canvas.yview)
        scrollbar.pack(side=tkinter.LEFT, fill=tkinter.Y)

        helpinfo = MalGen.MalGen.filetostring("Help.txt")#Gets instructions from Help.txt
        helptext = tkinter.Label(canvas, bg=framecolour,text = helpinfo,width=300)
        helptext.config(justify="left",anchor="w",font=("Sans", 10))
        helptext.place(x=40,y=70)
        canvas.create_window(0, 0, window=helptitle, anchor=tkinter.NW)
        canvas.create_window(0, 70, window=helptext, anchor=tkinter.NW)

        canvas.config(yscrollcommand=scrollbar.set)
        
        canvas.config(scrollregion=canvas.bbox("all"))
    
    @classmethod
    def obfuscate(cls,finbox):#Obfuscates code
        
        if finbox.curselection()==():#Checks if a file has been selected
            showerror("Error","Please select a file.")
        for i in finbox.curselection():
            showinfo("Info","Obfuscating....\nPress OK to continue.")
            try:
                MalGen.MalGen.obfuscate(finbox.get(i))#Sends code to obfuscate function
                showinfo("Info","Code has been obfuscated successfully.\nName: Obfuscated"+finbox.get(i))
                finbox.insert(tkinter.END,"Obfuscated"+finbox.get(i))#Adds new file to ListBox

            except Exception:
                showerror("Error","Error obfuscating, check connection.")

    @classmethod
    def run(cls):#The main function for this class
        cls.initialise()
        randomgen = RandomCGen.RandomCGen()#Create singleton randomgen
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
        genbutton = tkinter.Button(frame, text = "Generate!",width = 10,fg = '#ffffff',
                                   bg = buttoncolour,command=lambda:cls.sendprompt(
                                       randomgen,
                                       insertnuminp,
                                       inserttypeinp,
                                       listbox,
                                       files,
                                       allfiles))
        genbutton.place(x=250,y= 160)

        cls.refreshlist(listbox,files,allfiles)

        #refresh file list button
        refbutton = tkinter.Button(frame, text = "Refresh",width = 16, fg = '#ffffff',
                                   bg = buttoncolour,command=lambda: cls.refreshlist(listbox,files,allfiles))
        refbutton.place(x=50,y= 385)

        #all files button
        allfbutton = tkinter.Button(frame, text = "All",width = 6,fg = '#ffffff', 
                                    bg = buttoncolour,command=lambda: cls.allset(listbox,files,allfiles))
        allfbutton.place(x=120,y= 195)

        #new files button
        newfbutton = tkinter.Button(frame, text = "New",width = 6,fg = '#ffffff', bg = buttoncolour,
                                    command=lambda: cls.newset(listbox,files,allfiles))
        newfbutton.place(x=50,y= 195)
        listboxlab = tkinter.Label(frame,bg=framecolour, text = "default new")
        listboxlab.config(font=("Sans", 7))
        listboxlab.place(x=180,y=210)

        #compile button
        compilebutton = tkinter.Button(frame, text = "Compile!",width = 10,fg = '#ffffff',
                                       bg = buttoncolour,command=lambda:cls.compile(randomgen,listbox))
        compilebutton.place(x=250,y= 385)

        #read file button
        readbutton = tkinter.Button(frame, text = "Read file",width = 10,fg = '#ffffff',
                                    bg = buttoncolour,command=lambda:cls.read(randomgen,True,listbox))
        readbutton.place(x=250,y= 360)

        #malware listbox
        malbox = tkinter.Listbox(frame, bg=menucolour,height= 10,listvariable=files)
        malbox.place(x=420, y= 90)
        malboxlab = tkinter.Label(frame, bg=framecolour, text="Malicious Pending")
        malboxlab.place(x=420,y=70)
        malboxlab.config(font=("Sans", 8))

        #transfer file button
        transbutton = tkinter.Button(frame, text = "Make malicious",width = 15,
                                     fg = '#ffffff',bg = buttoncolour,command=lambda:cls.transfer(malbox,listbox))
        transbutton.place(x=250,y= 411)

        #remove file button
        rembutton = tkinter.Button(frame, text = "Remove file",width = 16,fg = '#ffffff',
                                   bg = buttoncolour,command=lambda:cls.rem(malbox))
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
        readfinbutton = tkinter.Button(frame, text = "Read file",width = 10,fg = '#ffffff',
                                       bg = buttoncolour,command=lambda:cls.read(randomgen,False,finbox))
        readfinbutton.place(x=615,y= 360)
        
        #compile button
        compilebutton = tkinter.Button(frame, text = "Compile!",width = 10,fg = '#ffffff',
                                       bg = buttoncolour,command=lambda:cls.compile(randomgen,finbox))
        compilebutton.place(x=615,y= 385)
        
        #MalwareCheck buttons
        mcbutton = tkinter.Button(frame, text = "Malware Check",width = 15,fg = '#ffffff',
                                  bg = buttoncolour,command=lambda:cls.check(finbox))
        mcbutton.place(x=615,y= 410)    
        mcbutton2 = tkinter.Button(frame, text = "Malware Check",width = 15,fg = '#ffffff',
                                   bg = buttoncolour,command=lambda:cls.check(listbox))
        mcbutton2.place(x=250,y= 435)

        #malware combobox
        curr_mal = tkinter.StringVar()
        malcombo = ttk.Combobox(frame, textvariable=curr_mal,width = 20) 
        malcombo['values'] = ('None', 'Keylogger', 'Directory Encryption') 
        malcombo.place(x=550,y=160)
        checkmalint = tkinter.IntVar()
        checkdevint = tkinter.IntVar()
        checkjailint = tkinter.IntVar()
        checkmal = tkinter.Checkbutton(frame, text='Malboy',bg=framecolour,variable=checkmalint, onvalue=1, offvalue=0)
        checkdev = tkinter.Checkbutton(frame, text='Devilinci',bg=framecolour,variable=checkdevint, onvalue=1, offvalue=0)
        checkjail = tkinter.Checkbutton(frame,bg=framecolour,variable=checkjailint, onvalue=1, offvalue=0)
        checkmal.place(x=550,y=130)
        checkdev.place(x=613,y=130)
        checkjail.place(x=680,y=130)
        jailbreak = tkinter.StringVar()
        jailcombo = ttk.Combobox(frame, textvariable=jailbreak,width = 7)
        jailcombo['values'] = ('GOD', 'EVIL', 'DEVELOPER')  
        jailcombo.place(x=700,y=130)

        #Go button
        gobutton = tkinter.Button(frame,text = "Go!", width = 8, height = 3,fg = '#ffffff',
                                  bg = buttoncolour,command=lambda:cls.go(finbox,malbox,malinp,checkdevint,checkmalint,curr_mal,checkjailint,jailbreak))
        gobutton.place(x=685,y=200)

        #Help button
        helpbutton = tkinter.Button(frame,text = "Help", width = 8,fg = '#ffffff',bg = buttoncolour,command=lambda:cls.help())
        helpbutton.place(x=730,y=5)

        #Obfuscate button
        obfbutton = tkinter.Button(frame,text = "Obfuscate", width = 15,fg = '#ffffff',
                                   bg = buttoncolour,command=lambda:cls.obfuscate(finbox))
        obfbutton.place(x=615,y=435)
        cls.gui.mainloop()

    



if __name__ == "__main__":
    GUI.run()