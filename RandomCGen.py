import GPTAPI
import re
import os

genfiles = list()

class RandomCGen(object):
    
    
    def __init__(self):
        self = self
        
    error = 0  
    

    @classmethod    
    def gencode(cls,count, type): #generates code
        print("Generating code....")
        samples = GPTAPI.GPTAPI.generate_response("Generate "+ str(count)+ " C code snippets with the following task:\n"\
                                                  + type+".\n Give no explanations about what the code is.\n"\
                                                  +" The code should have good readability and should be simple. ") #generate code snippets
    
        print("Done!")
        print("Dividing code samples into single samples....")
        samplelist = samples.split("```c") #split given code samples
        print("Done!")
    

        dir_path = r'Samples' #set where the files will be made
        fcount = 0
        print("Writing samples to files....")
        for path in os.listdir(dir_path): #count current numbers of files in directory
        
            fcount += 1
        try:
            
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
                genfiles.append("sample"+str(fcount+i)+".c")

            
        
            print("All files written!")
            return genfiles
        except Exception:
            cls.error = 1
            print("Error, please retry")
            return[]
    @classmethod    
    def compilecode(cls,file): #compiles code
        try:                  
            os.system("gcc "+file+" -o "+file[:-1]+"exe")
            generated = False
            for path in os.listdir("Samples"):
                if "Samples/"+path == file[:-1]+"exe":
                    generated=True
            if generated == True:
                return 1
            else:
                return 0
        except Exception:
            return 0
        
    
    
    @classmethod    
    def debug(cls,file):
        debfile = open("Samples/"+file)
        currcode = debfile.read()
        debfile.close()
        
        newcode = GPTAPI.GPTAPI.generate_response("PLEASE DEBUG THIS CODE, ONLY OUTPUT CODE. If the code is already correct then just return the code: "+currcode )
        

        try:
            processed = newcode.split("```")
            processed[1] = processed[1][1:]
            return processed[1]
            
        except Exception:
            return currcode
            
    
    
        
    