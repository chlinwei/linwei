try:
    x = 100
except ZeroDivisionError as e :
    print('ZeroDivisionError:',e)
except StopIteration as e :
    print('StopIteration:',e)
else: #上面的except都接受不到错误,则执行else语句
    print("no error")
finally:
    print("finally....")
