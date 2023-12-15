import os
from GPTAPI import GPTAPI
class MalGen:
    def mostvul(files): #Find most vulnerable of produced files
        prompt = "What does this code do and how could this be vulnerable to underhanded techniques to skew the vote count in a nominees favour? Return the associated number: \n"
        count = 1
        for i in files:
            file = MalGen.filetostring(i)
            prompt = prompt+"\n"+str(count)+". \n ```c \n"+file+"\n ```"
            count+=1
        prompts = [prompt,"How would this be done in code?"]
        print(GPTAPI.multi_gen(prompts))


    def filetostring(file): #Convert the file text into a string
        with open(file) as fileOpen:
            filestr = fileOpen.read()
        return filestr