from aip import AipOcr

APP_ID = '18870544'
API_KEY = 'umFuqwzgZNhcYlaXzGY6XzjY'
SECRET_KEY = 'PQlxan58loO4vFLmsCck9o1agI1sBTRf'
client = AipOcr(APP_ID, API_KEY, SECRET_KEY)

def use_ocr(img):
    try:
        result = client.basicGeneral(img)['words_result']
        words = ''
        for words_dict in result:
            words += words_dict['words']
        # print(words)
        return words
    except:
        print("图片格式不对，识别失败！")

def ocr_words():
    with open('xkx.png', 'rb') as f:
        img = f.read()
    return use_ocr(img)

# if __name__ == '__main__':
#     ocr_words()