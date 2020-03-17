import requests

headers = {'User-Agent': 
'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/55.0.2883.87 UBrowser/6.2.3831.602 Safari/537.36'}
response = requests.get('https://www.baidu.com/', headers = headers, timeout = 15)
print(response)
with open('Baidu.html', 'wb') as f:
    f.write(response)