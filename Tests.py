import GPTAPI
import MalwareCheck
import RandomCGen
import os
def apitest():
    print("GPTAPI TESTS")

    #Test 1, API response should include the word hello
    test1str = GPTAPI.generate_response("Say hello, dont code it.")
    if "hello"or"Hello" in test1str: 
        print("TEST 1 SUCCESS")
    else:
        print("TEST 1 FAIL")


    #Test 2, API response should include the beginning of a c snippet
    test2str = GPTAPI.generate_response("Write a simple c code snippet")
    if "```c" in test2str:
        print("TEST 2 SUCCESS")
    else:
        print("TEST 2 FAIL")

def cgentest():
    print("RANDOMCGEN TESTS")

    #Test1, file count should grow
    dir_path = r'Samples'
    fcount = 0
    for path in os.listdir(dir_path): #count current numbers of files in directory
        
        fcount += 1
    #blockPrint()
    RandomCGen.gencode(1,"")
    #enablePrint()
    newfcount = 0
    for path in os.listdir(dir_path): #count current numbers of files in directory
        newfcount += 1
    if newfcount>fcount:
        print("TEST 1 SUCCESS")
    else:
        print("TEST 1 FAIL")




apitest()
cgentest()