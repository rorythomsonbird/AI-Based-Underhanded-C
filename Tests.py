import GPTAPI
import MalwareCheck
import RandomCGen
def apitest():
    print("GPTAPI TESTS")
    if "hello" in GPTAPI.generate_response("Say hello"): #Test 1, API response should include the word hello
        print("TEST 1 SUCCESS")
    else:
        print("TEST 1 FAIL")

    if "```c" in GPTAPI.generate_response("Write a simple c code snippet"):
        print("TEST 2 SUCCESS")
    else:
        print("TEST 2 FAIL")
apitest()