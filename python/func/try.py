#错误没有处理,则会一直往上抛
try:
    r = 10/0
    print('result:',r)
except BaseException as e: #注意BaseException是所有异常的基类,所以这个类能接受所有的异常,所以不要把基类放在最前面
    print('BaseException:',e)
except ZeroDivisionError as e: #接受不到错误
    print("ZeroDivisionError:",e)
finally:
    print("finally...")






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
