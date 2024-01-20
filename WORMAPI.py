import requests
import json
class WORMAPI:
    def send_message():
        url = f"https://flowgpt.com/p/wormgpt-6"
        headers = {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.93 Safari/537.36"
        }
        response = requests.get(url, headers=headers)
        print(response.status_code)