#coding:utf-8
import re
import urllib
import os
import time
import urllib2
import cookielib

#时间2017-7-28

def get_xsrf(opener):
    html = opener.open(HOME_URL).read()
    p = r'name=\"_xsrf\" value=\"(.*?)\"'
    m =  re.search(p,html)
    return m.group(1)

HOME_URL= 'https://www.zhihu.com/#signin'
LOGIN_URL = 'https://www.zhihu.com/login/phone_num'
agent = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.11; rv:54.0) Gecko/20100101 Firefox/54.0"
PHONE_NUM='15345710576'
PASSWD='linwei232529'
cj = cookielib.CookieJar()
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))

_xsrf = get_xsrf(opener)
data = {
    'phone_num':PHONE_NUM,
    '_xsrf':_xsrf,
    'password':PASSWD,
    'captcha_type':'en',
}
headers = {
    "Host": "www.zhihu.com",
    "Referer": "https://www.zhihu.com/",
    'User-Agent': agent,
    'X-Xsrftoken':_xsrf,
    'X-Requested-With':"XMLHttpRequest"
}
print data
encode_data = urllib.urlencode(data)
request = urllib2.Request(LOGIN_URL,encode_data,headers=headers)
response = opener.open(request).read()
print response
if eval(response)['r'] == 1:
    randomtime = str(int(time.time()*1000))
    print  randomtime
    captchaurl = 'https://www.zhihu.com/captcha.gif?r=' + \
                 randomtime + "&type=login&lang=en"
    request = urllib2.Request(captchaurl,headers=headers)
    captcharesponse = opener.open(request)
    with open('a.png','wb') as f:
        f.write(captcharesponse.read())
    os.startfile('a.png')
    captcha = raw_input('请输入验证码:')
    print(captcha)
    data['captcha'] = captcha
    print data
    encode_data = urllib.urlencode(data)
    request = urllib2.Request(LOGIN_URL,encode_data,headers=headers)
    loginresponse = opener.open(request)
    #print loginresponse.read()
    print eval(loginresponse.read())['r']
    request = urllib2.Request(HOME_URL,headers=headers)
    html = opener.open(request).read()
    with open("a.html","w") as f:
        f.write(html)

