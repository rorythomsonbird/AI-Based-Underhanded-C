import requests
import json
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
import time
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC


class WORMAPI:
    def send_message():
        url = f"https://flowgpt.com/p/wormgpt-6" #URL
        options = webdriver.ChromeOptions()
        options.add_argument('--ignore-ssl-errors=yes')
        options.add_argument('--ignore-certificate-errors')
        driver = webdriver.Chrome(options=options)
        driver.get(url)
        time.sleep(3)
        signin = driver.find_element(By.ID, 'menu-button-:r15:')
        signin.click()
        time.sleep(10)
        #Get around the focus guard
        guarddelete = driver.find_element(By.CSS_SELECTOR,"div[data-focus-guard='true'][tabindex='0'][style='width: 1px; height: 0px; padding: 0px; overflow: hidden; position: fixed; top: 1px; left: 1px;'][data-aria-hidden='true'][aria-hidden='true']")
        driver.execute_script("arguments[0].parentNode.removeChild(arguments[0]);", guarddelete)
        guarddelete = driver.find_element(By.CSS_SELECTOR,"div.chakra-portal[data-aria-hidden='true'][aria-hidden='true']")
        driver.execute_script("arguments[0].parentNode.removeChild(arguments[0]);", guarddelete)
        #email = 
        #email.send_keys("wormywormman2@gmail.com")
        time.sleep(30)
        textarea = driver.find_element('css selector', 'textarea[data-testid="chat-input-textarea"]')
        button = driver.find_element('css selector', 'button[aria-label="Send"]')

        textarea.send_keys("Hello")
        button.click()
        time.sleep(300)
    
    #def gmaillogin():


        
        
      