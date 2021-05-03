from urllib.parse import quote_plus
from bs4 import BeautifulSoup
from selenium import webdriver

url = "https://www.dsm-dms.com/"

driver = webdriver.Chrome("C:\chromedriver_win32\chromedriver.exe")
driver.get(url)

html = driver.page_source
soup = BeautifulSoup(html)

content = soup.select(".meal--card--content--wrapper")

morning = content[0].select(".meal--card--content")
lunch = content[1].select(".meal--card--content")
dinner = content[2].select(".meal--card--content")

print("[DSM 아침 급식]---------------------------------")
for i in morning:
    print("■ " + i.get_text())
print()

print("[DSM 점심 급식]---------------------------------")
for i in lunch:
    print("■ " + i.get_text())
print()

print("[DSM 저녁 급식]---------------------------------")
for i in dinner:
    print("■ " + i.get_text())
print()

driver.close()