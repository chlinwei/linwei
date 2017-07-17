#coding:utf-8
#logging.exception(e):打印错误信息

import logging

def foo(s):
    return 10 / int(s)
def bar(s):
    return foo(s)*2

def main():
    try:
        bar('0')
    except Exception as e:
        logging.exception(e) 
        print(e)

main()
print("END")
