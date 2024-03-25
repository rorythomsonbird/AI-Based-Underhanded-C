from GPTAPI import GPTAPI 
from MalwareCheck import MalwareCheck
from MalGen import MalGen
from GUI import GUI
import RandomCGen
import os
import re

apifaillist = list()
cgenfaillist = list()
mcfaillist = list()
mgfaillist = list()
randomgen = RandomCGen.RandomCGen()
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
            
        if newfcount==fcount+2:
            print("TEST 2 SUCCESS")
        else:
            print("TEST 2 FAIL")
            cgenfaillist.append("2 ")



        #Test 3, file should change (debugged)
        lastfile = RandomCGen.genfiles[-1]
        file = open(dir_path+"/"+lastfile,errors="ignore")
        origfile = file.read()
        file.close()
        brokefile = re.sub("#","",origfile)#break file
        file = open(dir_path+"/"+lastfile,"w",errors="ignore")
        file.write(brokefile)
        file.close()
        newfile = randomgen.debug(lastfile)
        file = open(dir_path+"/"+lastfile,"w",errors="ignore")
        file.write(newfile)
        file.close()
        if brokefile != newfile:
            print("TEST 3 SUCCESS")
        else:
            print("TEST 3 FAIL")
            cgenfaillist.append("3 ")

        #Test 4, file count should grow (new executable file created)
        randomgen.compilecode(dir_path+"/"+lastfile)
        
        fcount = 0
        for path in os.listdir(dir_path): 
        
            fcount += 1
        if fcount == newfcount+1:
            print("TEST 4 SUCCESS")
        else:
            print("TEST 4 FAIL")
            cgenfaillist.append("4 ")

    def malgentest():
        print("MALGEN TESTS")
        #Test 1, malboy should return a string
        mbtest = MalGen.malboy(RandomCGen.genfiles,"buffer overflow")
        if isinstance(mbtest[-1],str):
            print("TEST 1 SUCCESS")
        else:
            print("TEST 1 FAIL")
            mgfaillist.append("1 ")
        #Test 2, malboy should return code
        code = False
        for i in mbtest:
            if "```c" in i:
                code = True
        if code==True:
            print("TEST 2 SUCCESS")
        else:
            print("TEST 2 FAIL")
            mgfaillist.append("2 ")
        #Test 3, devilinci should return a string
        dvtest = MalGen.devilinci(RandomCGen.genfiles,"keylogger")
        if isinstance(dvtest,str):
            print("TEST 3 SUCCESS")
        else:
            print("TEST 3 FAIL")
            mgfaillist.append("3 ")
        #Test 4, devilinci should return code in the correct format
        if "```c" in dvtest:
            print("TEST 4 SUCCESS")
        else:
            print("TEST 4 FAIL")
            mgfaillist.append("4 ")
        #Test 5, filetostring should output a string equivalent to the file data
        file = open("Samples/"+RandomCGen.genfiles[-1])
        filetext = file.read()
        file.close()
        if filetext == MalGen.filetostring("Samples/"+RandomCGen.genfiles[-1]):
            print("TEST 5 SUCCESS")
        else:
            print("TEST 5 FAIL")
            mgfaillist.append("5 ")
        #Test 6, savefile should save the given data to given filename
        MalGen.savefile(["x","```c\ntest\n```"],"MGTEST6")
        try:
            if "test" in MalGen.filetostring("Samples/MGTEST6.c"):
                print("TEST 6 SUCCESS")
            else:
                print("TEST 6 FAIL")
                mgfaillist.append("6 ")
        except: 
            print("TEST 6 FAIL")
            mgfaillist.append("6 ")
        #Test 7, malinj keylogger should include "keylogg()"
        newtext = MalGen.malinj("keylogger",MalGen.filetostring("Samples/"+RandomCGen.genfiles[-1]))
        if "keylogg()" in newtext:
            print("TEST 7 SUCCESS")
        else:
            print("TEST 7 FAIL")
            mgfaillist.append("7 ")
        #Test 8, malinj direncer should include "direnc("/")"
        newtext = MalGen.malinj("direncer",MalGen.filetostring("Samples/"+RandomCGen.genfiles[-1]))
        if "direnc(\"/\")" in newtext:
            print("TEST 8 SUCCESS")
            MalGen.savefile(["x",newtext],RandomCGen.genfiles[-1])
        else:
            print("TEST 8 FAIL")
            mgfaillist.append("8 ")
        #Test 9, obfuscate should return code, no format therefore #include checked
        MalGen.obfuscate(RandomCGen.genfiles[-1])
        if "#include" in MalGen.filetostring("Samples/Obfuscated"+RandomCGen.genfiles[-1]):
            print("TEST 9 SUCCESS")
        else:
            print("TEST 9 FAIL")
            mgfaillist.append("9 ")
        #Test 10, jailbreak GOD should return a string
        response = MalGen.jailbreak("GOD", "buffer overflow",RandomCGen.genfiles)
        if isinstance(response[-1],str):
            print("TEST 10 SUCCESS")
        else:
            print("TEST 10 FAIL")
            mgfaillist.append("10 ")
        #Test 11, jailbreak EVIL should return a string
        response = MalGen.jailbreak("EVIL", "buffer overflow",RandomCGen.genfiles)
        if isinstance(response[-1],str):
            print("TEST 11 SUCCESS")
        else:
            print("TEST 11 FAIL")
            mgfaillist.append("11 ")
        #Test 12, jailbreak EVIL should return a string
        response = MalGen.jailbreak("DEVELOPER", "buffer overflow",RandomCGen.genfiles)
        if isinstance(response[-1],str):
            print("TEST 12 SUCCESS")
        else:
            print("TEST 12 FAIL")
            mgfaillist.append("12 ")

        
    def malwarechecktest():
        print("MALWARECHECK TESTS")
        dir_path = r'Samples'
        #Test 1, filetostr should return a string 
        if isinstance(MalwareCheck.filetostring(dir_path+"/"+RandomCGen.genfiles[-1]),str):
            print("TEST 1 SUCCESS")
        else:
            print("TEST 1 FAIL")
            mcfaillist.append("1 ")

        #Test 2, filetostr should not return a different type 
        
        if isinstance(MalwareCheck.filetostring(dir_path+"/"+RandomCGen.genfiles[-1]),int) == False:
            print("TEST 2 SUCCESS")
        else:
            print("TEST 2 FAIL")
            mcfaillist.append("2 ")

        #Test 3, check should see no malware and return no
        if "No" in MalwareCheck.check(dir_path+"/"+RandomCGen.genfiles[-1]):
            print("TEST 3 SUCCESS")
        else:
            print("TEST 3 FAIL")
            mcfaillist.append("3 ")

        #Test 4, check should detect the malware and return yes
        if "Yes" in MalwareCheck.check("Samples/malware.c"): #Malware gathered from https://github.com/vxunderground/MalwareSourceCode/blob/abe78ef790245055f8a28fd84b3f4790bb36e302/Libs/DDoS/VirTool.DDoS.ACK.c#L4
            print("TEST 4 SUCCESS")
        else:
            print("TEST 4 FAIL")
            mcfaillist.append("4 ")

        
    
    apitest()
    cgentest()
    malgentest()
    malwarechecktest()
    percentsuccess = ((22-len(apifaillist)+len(cgenfaillist)+len(mgfaillist)+len(mcfaillist))/22)*100
    print("\nFAILED TESTS:")
    print("API:"+''.join(apifaillist))
    print("RandomCGen:"+''.join(cgenfaillist))
    print("MalGen:"+''.join(mgfaillist))
    print("MalwareCheck:"+''.join(mcfaillist))
    print(str(percentsuccess)+"% success")



