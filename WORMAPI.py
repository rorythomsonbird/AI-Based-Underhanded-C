import requests
import json
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time

class WORMAPI:
    def send_message():
        url = f"https://flowgpt.com/p/wormgpt-6" #URL
        options = webdriver.ChromeOptions()
        options.add_argument('--ignore-ssl-errors=yes')
        options.add_argument('--ignore-certificate-errors')
        driver = webdriver.Chrome(options=options)
        driver.get(url)
        time.sleep(30)
        textarea = driver.find_element('css selector', 'textarea[data-testid="chat-input-textarea"]')
        button = driver.find_element('css selector', 'button[aria-label="Send"]')

        textarea.send_keys("Hello")
        button.click()
        time.sleep(300)
        
        
      