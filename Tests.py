from GPTAPI import GPTAPI 
from MalwareCheck import MalwareCheck
import RandomCGen
import os
class Tests:
    def apitest():
        print("GPTAPI TESTS")

        #Test 1 - response test, API response should include the word hello
        test1str = GPTAPI.generate_response("Say hello, dont code it.")
        if "hello"or"Hello" in test1str: 
            print("TEST 1 SUCCESS")
        else:
            print("TEST 1 FAIL")


        #Test 2 - code response test, API response should include the beginning of a c snippet
        test2str = GPTAPI.generate_response("Write a simple c code snippet")
        if "```c" in test2str:
            print("TEST 2 SUCCESS")
        else:
            print("TEST 2 FAIL")

    def cgentest():
        print("RANDOMCGEN TESTS")
        randomgen = RandomCGen.RandomCGen()
        #Test 1 - generated c output to file, file count should grow (new C files generated)
        dir_path = r'Samples'
        fcount = 0
        for path in os.listdir(dir_path): #count current numbers of files in directory
        
            fcount += 1
        #blockPrint()
        randomgen.gencode(1,"")
       
        newfcount = 0
        for path in os.listdir(dir_path): #count current numbers of files in directory 
            newfcount += 1
        if newfcount == fcount+1:
            print("TEST 1 SUCCESS")
        else:
            print("TEST 1 FAIL")



        #Test 2 - multiple file generations, file count should grow twice (2 new C files generated)
        fcount = 0
        for path in os.listdir(dir_path): 
        
            fcount += 1
        randomgen.gencode(2,"")
       
        newfcount = 0
        for path in os.listdir(dir_path): 
            newfcount += 1
            if ".c" in path:
                lastfile = path
        if newfcount==fcount+2:
            print("TEST 2 SUCCESS")
        else:
            print("TEST 2 FAIL")



        #Test 3, file should change (debugged)
        file = open(dir_path+"/"+lastfile,errors="ignore")
        origfile = file.read()
        file.close()
        randomgen.debug(lastfile)
        file = open(dir_path+"/"+lastfile)
        newfile = file.read()
        file.close()
        if origfile != newfile:
            print("TEST 3 SUCCESS")
        else:
            print("TEST 3 FAIL")

        #Test 4, file count should grow (new object file created)
        randomgen.compilecode(dir_path+"/"+lastfile)
        fcount = 0
        for path in os.listdir(dir_path): 
        
            fcount += 1

        if fcount == newfcount+1:
            print("TEST 4 SUCCESS")
        else:
            print("TEST 4 FAIL")

        
    def malwaretest():
        print("MALWARECHECK TESTS")
        dir_path = r'Samples'
        #Test 1, filetostr should return a string 
        fcount = 0
        for path in os.listdir(dir_path): 
            if ".c" in path:
                fcount += 1
                lastfile = path
        if isinstance(MalwareCheck.filetostring(dir_path+"/"+lastfile),str):
            print("TEST 1 SUCCESS")
        else:
            print("TEST 1 FAIL")

        #Test 2, filetostr should not return a different type 
        fcount = 0
        for path in os.listdir(dir_path): 
            if ".c" in path:
                fcount += 1
                lastfile = path
        if isinstance(MalwareCheck.filetostring(dir_path+"/"+lastfile),int) == False:
            print("TEST 2 SUCCESS")
        else:
            print("TEST 2 FAIL")


    apitest()
    cgentest()
    malwaretest()