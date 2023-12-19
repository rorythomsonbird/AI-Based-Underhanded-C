import requests
from flask import Flask, request, jsonify
from bs4 import BeautifulSoup

app = Flask(__name__)

@app.route('/api', methods=['POST'])
def api():
    url = 'https://flowgpt.com/p/wormgpt-6'
    

if __name__ == '__main__':
    

    app.run()