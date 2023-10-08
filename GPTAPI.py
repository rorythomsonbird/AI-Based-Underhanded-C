import openai
import os

openai.api_key = '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' #API key
#prompt = f"I am an AI language model."


def generate_response(input): #Sends a prompt to GPT to be answered

    response = openai.ChatCompletion.create(
    model="gpt-3.5-turbo", #GPT model used in this project
    messages=[
            #{"role": "system", "content": prompt},
            {"role": "user", "content": input},
        ]
    )
    
    message = response.choices[0].message.content
    return message


def main():
    gpt_response = generate_response("Hello.")
    print(gpt_response)

