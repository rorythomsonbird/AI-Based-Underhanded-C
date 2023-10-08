import openai
import os

openai.api_key = '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' #API key



def generate_response(input): #Sends a prompt to GPT to be answered

    response = openai.ChatCompletion.create(
    model="gpt-3.5-turbo", #GPT model used in this project
    messages=[
            {"role": "system", "content": "I am a skilled C developer and can code advanced c code. I also am able to recognise malware easily. I enjoy commenting heavily on my code to ensure readability."},
            {"role": "user", "content": input},
            
        ]
    )
    
    message = response.choices[0].message.content
    return message


def main():
    gpt_response = generate_response("Hello.")
    print(gpt_response)

