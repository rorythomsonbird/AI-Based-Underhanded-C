from GPTAPI import GPTAPI 
from MalwareCheck import MalwareCheck
import RandomCGen
import os

apifaillist = list()
cgenfaillist = list()
mcfaillist = list()
class Tests:
    
    def apitest():
        print("GPTAPI TESTS")

        #Test 1 - response test, API response should include the word hello
        test1str = GPTAPI.generate_response("Say hello, dont code it.")
        if "hello"or"Hello" in test1str: 
            print("TEST 1 SUCCESS")
        else:
            print("TEST 1 FAIL")
            apifaillist.append("1 ")


        #Test 2 - code response test, API response should include the beginning of a c snippet
        test2str = GPTAPI.generate_response("Write a simple c code snippet")
        if "```c" in test2str:
            print("TEST 2 SUCCESS")
        else:
            print("TEST 2 FAIL")
            apifaillist.append("2 ")

    def cgentest():
        print("RANDOMCGEN TESTS")
        randomgen = RandomCGen.RandomCGen()
        #Test 1 - generated c output to file, file count should grow (new C files generated)
        dir_path = r'Samples'
        fcount = 0
        for path in os.listdir(dir_path): #count current numbers of files in directory
        
            fcount += 1

        randomgen.gencode(1,"")
        newfcount = 0
        for path in os.listdir(dir_path): #count current numbers of files in directory 
            newfcount += 1
        if newfcount == fcount+1:
            print("TEST 1 SUCCESS")
        else:
            print("TEST 1 FAIL")
            cgenfaillist.append("1 ")



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
            cgenfaillist.append("2 ")



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
            cgenfaillist.append("3 ")

        #Test 4, file count should grow (new object file created)
        randomgen.compilecode(dir_path+"/"+lastfile)
        
        fcount = 0
        for path in os.listdir(dir_path): 
        
            fcount += 1
        if fcount == newfcount+1:
            print("TEST 4 SUCCESS")
        else:
            print("TEST 4 FAIL")
            cgenfaillist.append("4 ")

        
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
            mcfaillist.append("1 ")

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
            mcfaillist.append("2 ")

        #Test 3, check should see no malware and return no
        if "No" in MalwareCheck.check("Samples/sample2.c"):
            print("TEST 3 SUCCESS")
        else:
            print("TEST 3 FAIL")
            mcfaillist.append("3 ")

        #Test 4, check should detect the malware and return yes
        if "Yes" in MalwareCheck.check("Samples/malware.txt"): #Malware gathered from https://github.com/vxunderground/MalwareSourceCode/blob/abe78ef790245055f8a28fd84b3f4790bb36e302/Libs/DDoS/VirTool.DDoS.ACK.c#L4
            print("TEST 4 SUCCESS")
        else:
            print("TEST 4 FAIL")
            mcfaillist.append("4 ")

        #Test 5, checksamples should output a list same size as number of samples and should contain yes or no
        samplecount = 0
        for path in os.listdir("Samples"):
            if '.obj' not in path:
                samplecount+=1
        checklist = MalwareCheck.checksamples()
        fail = False
        checkcount = 0
        while fail == False and checkcount < len(checklist):
            
            if "Yes" in checklist[checkcount] or "No" in checklist[checkcount]:
                fail = False
            else:
                fail = True
            checkcount +=1
        
        if checkcount == samplecount and fail == False:
            print("TEST 5 SUCCESS")
        else:
            print("TEST 5 FAIL")
            mcfaillist.append("5 ")
    
    apitest()
    cgentest()
    malwaretest()
    print("FAILED TESTS:")
    print("API:"+''.join(apifaillist))
    print("RandomCGen:"+''.join(cgenfaillist))
    print("MalwareCheck:"+''.join(mcfaillist))



