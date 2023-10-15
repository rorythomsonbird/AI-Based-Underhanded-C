import GPTAPI
import re
import os
from distutils.ccompiler import new_compiler

def gencode(count, type):
    #elevate.elevate()
    print("Generating code....")
    samples = GPTAPI.generate_response("Generate "+ str(count)+ " c code snippets that "+ type+". With no explanations about what the code is. code should have good readability and should be simple. ")
    print(samples)
    print("Done!")
    print("Dividing code samples into single samples....")
    samplelist = samples.split("```c")
    print("Done!")
    

    dir_path = r'Samples'
    fcount = 0
    print("Writing samples to files....")
    for path in os.listdir(dir_path):
        
        fcount += 1

    for i in range(1,count+1):
        samplelist[i] = re.sub('```', '', samplelist[i])

        #The below 3 lines are temporary until syntax check has been implemented
        samplelist[i] = re.sub('snippet '+str(i+1)+':', '', samplelist[i])
        samplelist[i] = re.sub('Snippet '+str(i+1)+':', '', samplelist[i])
        samplelist[i] = re.sub('Code', '', samplelist[i])
        samplelist[i] = re.sub(str(i+1)+'. ', '', samplelist[i])
        
        file = open("Samples/sample"+str(fcount+i)+".c","w")
        file.writelines(samplelist[i])
        file.close()
        print("Sample "+str(fcount+i)+ " done!")
        print("Compiling sample "+str(fcount+i)+"....")
        compilecode("Samples/sample"+str(fcount+i)+".c")
        print("Compiled!")
    
    print("All files written!")
    
        
def compilecode(file):
    compiler = new_compiler()
    compiler.compile([file])
    