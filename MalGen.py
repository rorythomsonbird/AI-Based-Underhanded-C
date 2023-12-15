import os
class MalGen:
    def mostvul(files):
        filestrs = ""
        count = 1
        for i in files:
            file = MalGen.filetostring(i)
            filestrs = filestrs+str(count)+". \n ```c \n"+file+"\n ```"
            count+=1
        print(filestrs)


    def filetostring(file): #Convert the file text into a string
        with open(file) as fileOpen:
            filestr = fileOpen.read()
        return filestr