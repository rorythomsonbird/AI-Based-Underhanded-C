import os
from GPTAPI import GPTAPI
class MalGen:
    def mostvul(files): #Find most vulnerable of produced files
        prompt = "which of the following code snippets is most vulnerable to underhanded techniques to skew the vote count in a nominee's favour: \n"
        count = 1
        for i in files:
            file = MalGen.filetostring(i)
            prompt = prompt+"\n"+str(count)+". \n ```c \n"+file+"\n ```"
            count+=1
        prompts = [prompt,"Using underhanded techniques make the code you just referred to skew the vote count in a hard to see way. ALTER THE CODE AND SHOW THIS", "Make the underhanded code more subtle in the code you are currently referring to"]
        replies =GPTAPI.multi_gen(prompts)
        


    def filetostring(file): #Convert the file text into a string
        with open(file) as fileOpen:
            filestr = fileOpen.read()
        return filestr