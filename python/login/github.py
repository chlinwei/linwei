#coding:utf-8
import re
import urllib
import urllib2
import cookielib

#time:2017-7-29
cj = cookielib.CookieJar()
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
LOGIN_URL='https://github.com/session'

def get_token(opener):
    html = opener.open('https://github.com/login').read()
    p = r'<input name=\"authenticity_token\" type=\"hidden\" value=\"(.*?)\"'
    x = re.search(p,html)
    return x.group(1)

data = {
    'commit':'Sing in',
    'utf8':'?',
    'login':'chlinwei',
    'password':'linwei232529',
    'authenticity_token':get_token(opener)
}
encode_data = urllib.urlencode(data)
agent = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/59.0.3071.115 Safari/537.36'
headers = {
    'User-Agent':agent
}
request = urllib2.Request(LOGIN_URL,encode_data,headers=headers)
response = opener.open(request)
print response.geturl()
with open("a.html",'w') as f:
    f.write(response.read())
