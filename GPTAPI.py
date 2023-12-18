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
        
        replies=[]
        for i in prompts: 
        
            
            
            chat = openai.Completion.create( 
                model="text-davinci-003", prompt=i,
                temperature = 0.5,  
                top_p       = 0.2,  
                max_tokens  = 1024,  
                presence_penalty = 0.0,  
                frequency_penalty = 0.0, 
                
            ) 
            
            reply = chat['choices'][0]['text'] 
            print(reply)
            replies.append(reply)
        
        return replies

    

