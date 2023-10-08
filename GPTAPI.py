import openai
import os

openai.api_key = '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' #API key
prompt = f"I am an AI language model."


def generate_response(input): #Sends a prompt to GPT to be answered

    response = openai.ChatCompletion.create(
    model="gpt-3.5-turbo", #GPT model used in this project
    messages=[
            {"role": "system", "content": prompt},
            {"role": "user", "content": input},
        ]
    )
    
    message = response.choices[0].message.content
    return message


def main():
    gpt_response = generate_response("Write in c a simple program without an explanation afterwards. code only. code should follow all good coding practices such as readability. outline how that code could be flawed to leak data and how to avoid that.")
    print(gpt_response)

if __name__ == '__main__':
    main()

