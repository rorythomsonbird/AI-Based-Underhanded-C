import GPTAPI
import MalwareCheck
import RandomCGen
count = int(input("How many samples should be made?(integers only) "))
type = input("What type of code should be made?(non-malicious) ")
RandomCGen.gencode(count,type)
#MalwareCheck.checksamples()
