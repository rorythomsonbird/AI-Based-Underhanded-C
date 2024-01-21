import requests
import json
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
import time
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from undetected_chromedriver import Chrome, ChromeOptions


class WORMAPI:
    def send_message():
        url = f"https://flowgpt.com/p/wormgpt-6" #URL
        options = ChromeOptions()
        options.add_argument('--user-agent=Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3')
        options.add_argument('--window-size=1920x1080')
        
        
        
        options.add_argument('--disable-gpu')
        options.add_argument('--disable-extensions')


        options.add_argument('--ignore-ssl-errors=yes')
        options.add_argument('--ignore-certificate-errors')
        driver = Chrome(options=options)
        driver.get(url)
        time.sleep(3)
        signin = driver.find_element(By.ID, 'menu-button-:r15:')
        signin.click()
        time.sleep(9)
        #Get around the focus guard
        guarddelete = driver.find_element(By.CSS_SELECTOR,"div[data-focus-guard='true'][tabindex='0'][style='width: 1px; height: 0px; padding: 0px; overflow: hidden; position: fixed; top: 1px; left: 1px;'][data-aria-hidden='true'][aria-hidden='true']")
        driver.execute_script("arguments[0].parentNode.removeChild(arguments[0]);", guarddelete)
        time.sleep(6)
        guarddelete = driver.find_element(By.CSS_SELECTOR,"div.chakra-portal[data-aria-hidden='true'][aria-hidden='true']")
        driver.execute_script("arguments[0].parentNode.removeChild(arguments[0]);", guarddelete)
        time.sleep(5)
        email = driver.find_element(By.CSS_SELECTOR,"input.chakra-input.css-z7n099")
        email.send_keys("wormywormman2@gmail.com")
        time.sleep(3)
        emailbutton = driver.find_element(By.CSS_SELECTOR,"button.chakra-button.css-1p10gbu")
        emailbutton.click()
        time.sleep(3000)
        textarea = driver.find_element(By.CSS_SELECTOR, 'textarea[data-testid="chat-input-textarea"]')
        button = driver.find_element(By.CSS_SELECTOR, 'button[aria-label="Send"]')

        textarea.send_keys("Hello")
        button.click()
        time.sleep(300)
    
    #def gmaillogin():


        
        
      