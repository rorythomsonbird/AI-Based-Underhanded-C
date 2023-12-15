from GPTAPI import GPTAPI 
from MalwareCheck import MalwareCheck 
from RandomCGen import RandomCGen 
import os
from MalGen import MalGen
class Main:
    def main():
        # count = int(input("How many samples should be made?(integers only) ")) #input how many samples should be generated 
        # type =  input("What type of code should be made?(non-malicious, for random code leave blank) ") #input what the code samples should do
        # if type != "":
        #     type = "that " + type
        # newfiles = RandomCGen.gencode(count,type)
        # print("Debugging...")
        # for i in newfiles:
        #     RandomCGen.debug(i)
        # print("Checking for malware...")
        # for i in newfiles:
        #     print(MalwareCheck.check("Samples/"+i))
        MalGen.mostvul(["Samples/sample40.c","Samples/sample41.c","Samples/sample42.c"])

if __name__ == "__main__":
    Main.main()