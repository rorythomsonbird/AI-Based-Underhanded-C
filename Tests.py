from GPTAPI import GPTAPI 
import MalwareCheck
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
            lastfile = path
        if newfcount==fcount+2:
            print("TEST 2 SUCCESS")
        else:
            print("TEST 2 FAIL")


        #Test 3, file count should grow (new object file created)
        randomgen.compilecode(dir_path+"/"+lastfile)
        fcount = 0
        for path in os.listdir(dir_path): 
        
            fcount += 1

        if fcount == newfcount+1:
            print("TEST 3 SUCCESS")
        else:
            print("TEST 3 FAIL")



    apitest()
    cgentest()