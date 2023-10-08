import GPTAPI
def gencode(count):
    samples = GPTAPI.generate_response("Generate "+ str(count)+ " c code snippets with no explanations about what the code is. code should have good readability and should be simple")
    print(samples)