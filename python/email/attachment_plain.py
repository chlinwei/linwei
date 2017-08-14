#coding:utf-8
#添加附件
from email import encoders
from email.header import Header
from email.mime.text import MIMEText
from email.MIMEMultipart import MIMEMultipart
from email.MIMEBase import MIMEBase
import smtplib
filename = '1.PNG'
from_addr = 'm15345710576@163.com'
password = 'xxxx'
to_addr = '862350707@qq.com'
smtp_server = 'smtp.163.com'
msg = MIMEMultipart()
msg['From'] = from_addr
msg['To'] = to_addr
msg['Subject'] = Header('来自SMTP的问候...','utf-8').encode()
msg.attach(MIMEText('hello,world','plain','utf-8'))
with open(filename,'rb') as f:
    mime = MIMEBase('image','png',filename=filename)
    mime.add_header('Content-Disposition','attachment',filename=filename)
    mime.add_header('Content-ID','<0>')
    mime.add_header('X-Attachment-ID','0')
    mime.set_payload(f.read())
    encoders.encode_base64(mime)
    msg.attach(mime)

server = smtplib.SMTP(smtp_server,25)
server.set_debuglevel(1) #调试信息
server.login(from_addr,password)
server.sendmail(from_addr,[to_addr],msg.as_string())
server.quit()
