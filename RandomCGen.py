import GPTAPI
import re
import os
def gencode(count):
    samples = GPTAPI.generate_response("Generate "+ str(count)+ " c code snippets with no explanations about what the code is. code should have good readability and should be simple. ")
    samplelist = samples.split("```c")
    print(samplelist[0])
    import os

# folder path
    dir_path = r'C:\Users\roryt\Desktop\Code\PROJECT\Samples'
    fcount = 0
    for path in os.listdir(dir_path):
        
        fcount += 1

    for i in range(1,count+1):
        samplelist[i] = re.sub('```', '', samplelist[i])
        samplelist[i] = re.sub('Snippet '+str(i+1)+':', '', samplelist[i])
        file = open("Samples/sample"+str(fcount+i+1)+".c","w")
        file.writelines(samplelist[i])
    print("finished")
        
        