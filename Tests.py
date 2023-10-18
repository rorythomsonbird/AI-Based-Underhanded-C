import GPTAPI
import MalwareCheck
import RandomCGen
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
apitest()