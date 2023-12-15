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
        messages=[{"role": "system", "content": "I am a skilled C developer and can code advanced c code."}]
        replies=[]
        for i in prompts: 
            message = i 
            
            messages.append( 
                {"role": "user", "content": message}, 
                ) 
            chat = openai.ChatCompletion.create( 
                model="gpt-3.5-turbo", messages=messages 
            ) 
            reply = chat.choices[0].message.content 
            replies.append(reply)
        
        return replies


