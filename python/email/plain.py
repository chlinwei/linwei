#coding:utf-8
#发送纯文本
#继承关系
#Message
#+- MIMEBase
#   +- MIMEMultipart
#   +- MIMENonMultipart
#      +- MIMEMessage
#      +- MIMEText
#      +- MIMEImage
from email import encoders
from email.header import Header
from email.mime.text import MIMEText
import smtplib
from_addr = 'm15345710576@163.com'
password = 'linwei359'
to_addr = '862350707@qq.com'
smtp_server = 'smtp.163.com'
msg = MIMEText('hello,world','plain','utf-8')
msg['From'] = from_addr
msg['To'] = to_addr
msg['To'] = 'hahahh'
msg['Subject'] = Header('来自SMTP的问候...','utf-8').encode()
server = smtplib.SMTP(smtp_server,25)
server.starttls() #加密
#server.set_debuglevel(1) #调试信息
server.login(from_addr,password)
server.sendmail(from_addr,[to_addr],msg.as_string())
server.quit()
