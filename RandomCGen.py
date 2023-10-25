import GPTAPI
import re
import os
from distutils.ccompiler import new_compiler

def gencode(count, type): #generates code
    print("Generating code....")
    samples = GPTAPI.generate_response("Generate "+ str(count)+ " c code snippets  "+ type+". With no explanations about what the code is. code should have good readability and should be simple. ") #generate code snippets
    
    print("Done!")
    print("Dividing code samples into single samples....")
    samplelist = samples.split("```c") #split given code samples
    print("Done!")
    

    dir_path = r'Samples' #set where the files will be made
    fcount = 0
    print("Writing samples to files....")
    for path in os.listdir(dir_path): #count current numbers of files in directory
        
        fcount += 1

    for i in range(1,count+1):
        samplelist[i] = re.sub('```', '', samplelist[i]) #remove unneeded ``` characters

        
        
        file = open("Samples/sample"+str(fcount+i)+".c","w") #open new file with original sample name
        tempsamplelist = samplelist[i].split("\n")
        del(tempsamplelist[len(tempsamplelist)-1]) #remove last 3 lines of code (either empty lines or comments by API)
        del(tempsamplelist[len(tempsamplelist)-1])
        del(tempsamplelist[len(tempsamplelist)-1])
        for j in range(len(tempsamplelist)): #add newline characters (they were removed in the split)
            tempsamplelist[j] = tempsamplelist[j] + "\n"
        samplelist[i] = tempsamplelist
        
        file.writelines(samplelist[i]) #write lines to file
        file.close()
        print("Sample "+str(fcount+i)+ " done!")
        print("Compiling sample "+str(fcount+i)+"....")
        compilecode("Samples/sample"+str(fcount+i)+".c")
        print("Compiled!")
    
    print("All files written!")
    
        
def compilecode(file): #compiles code
    compiler = new_compiler()
    try:
        compiler.compile([file])
    except Exception:
        print("Could not compile "+file+ " please compile manually.")
    