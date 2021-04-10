from aip import AipSpeech
from ocr import ocr_words
 
""" 你的 APPID AK SK """
APP_ID = '18872093'
API_KEY = 'a6Ns6EYn5CRyi4dbRIabtSRn'
SECRET_KEY = 'EFKGGbnieUwtPvxEDUXnrn6L8Uqh1ov7'
client = AipSpeech(APP_ID, API_KEY, SECRET_KEY)

def _spoken(words):
    result  = client.synthesis(words, 'zh', 1, {
        'vol': 3, 'spd':2, 'per': 3
    })
    try:
        with open('Auido2.mp3', 'wb') as f:
            f.write(result)
        
    except:
        print('语音朗读出错！')

if __name__ == '__main__':
    words = ocr_words()
    _spoken(words)