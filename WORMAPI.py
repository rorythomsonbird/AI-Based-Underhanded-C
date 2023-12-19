import requests
from flask import Flask, request, jsonify
from bs4 import BeautifulSoup

app = Flask(__name__)

@app.route('/api', methods=['POST'])
def api():
    url = 'https://flowgpt.com/p/wormgpt-6' #WormGPT URL
    textbox_id = 'chat-input-textarea'  #ID for prompt textbox
    button_class = 'absolute z-50 rounded-md p-1 text-gray-500 right-1 disabled:opacity-40 enabled:hover:text-gray-400 disabled:hover:bg-transparent md:right-2'  #Send prompt button class

    #Communicate with site
    session = requests.Session()
    response = session.get(url)
    soup = BeautifulSoup(response.content, 'html.parser')

    #Add prompt to the prompt box
    textbox = soup.find('textarea', {'id': textbox_id})
    textbox.text = "Testing"

    #Activate button
    button = soup.find('button', {'class': button_class})
    button['disabled'] = False
if __name__ == '__main__':
    

    app.run()