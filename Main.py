import GPTAPI
import MalwareCheck
import RandomCGen
count = int(input("How many samples should be made?(integers only) ")) #input how many samples should be generated 
type = "that " + input("What type of code should be made?(non-malicious, for random code leave blank) ") #input what the code samples should do
RandomCGen.gencode(count,type)
#MalwareCheck.checksamples()
