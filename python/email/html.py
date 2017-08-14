#coding:utf-8
from email import encoders
from email.header import Header
from email.mime.text import MIMEText
import smtplib
from_addr = 'm15345710576@163.com'
password = 'xxxx'
to_addr = '862350707@qq.com'
smtp_server = 'smtp.163.com'
#msg = MIMEText('hello,world','plain','utf-8')
html = '<html><body><p>我是lw</p> <a href="#">点我</a> </body></html>'
msg = MIMEText(html,'html','utf-8')
msg['From'] = from_addr
msg['To'] = to_addr
msg['Subject'] = Header('来自SMTP的问候...','utf-8').encode()
server = smtplib.SMTP(smtp_server,25)
#server.set_debuglevel(1) #调试信息
server.login(from_addr,password)
server.sendmail(from_addr,[to_addr],msg.as_string())
server.quit()
