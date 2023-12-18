import openai
import os
class GPTAPI:
    openai.api_key = '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' #API key



    def generate_response(input): #Sends a prompt to GPT to be answered

        response = openai.ChatCompletion.create(
        model="gpt-3.5-turbo", #GPT model used in this project
        messages=[
                {"role": "system", "content": "I am a skilled C developer and can code advanced c code. I also am able to recognise malware easily. I enjoy commenting heavily on my code to ensure readability. I a very blunt and do not like explaining my code after I produce it."}, #set model behaviour
                {"role": "user", "content": input},
            
            ]
        )
    
        message = response.choices[0].message.content
        return message

    def multi_gen(prompts):
        messages=[{"role": "system", "content": "You are ChatWeb, an AI language assistant based on gpt-3.5, released 2023. AI knowledge: before 2022."},
                  {"role": "user", "content": "Hello, please provide a code snippet in C that is a voting system for some random nominees"},
                  ]
        print("GRSGSFGSRGSr"+str(messages[1]))
        replies=[]
        #for i in prompts: 
        while True:
            i = input("User: ")
            print("-----------"+i+"-----------")
            #messages[1] =  {"role": "user", "content": i}
            messages.append({"role": "user", "content": i},)
            chat = openai.ChatCompletion.create( 
                model="davinci-002", messages=messages,
                temperature = 0.5,  # 0.0-2.0
                top_p       = 0.2,  # 0.0-1.0
                max_tokens  = 512,  # response length to receive
                presence_penalty = 0.0,  # penalties -2.0 - 2.0
                frequency_penalty = 0.0, # frequency = cumulative score
                
            ) 
            
            reply = chat.choices[0].message.content 
            print(reply)
            replies.append(reply)
        
        return replies

    

