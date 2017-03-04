#_*_coding:utf-8 _*_

#    异常类型           用途
#SyntaxError         语法错误
#IndentationError    缩进错误
#TypeError           对象类型与要求不符合
#ImportError         模块或包导入错误;一般路径或名称错误
#KeyError            字典里不存在的键
#NameError           变量不存在
#IndexError          下标超出序列范围
#IOError             输入/输出异常;一般是无法打开文件
#AttributeError      对象里没有属性
#KeyboardInterrupt   键盘接受到Ctrl+C
#Exception           通用的异常类型,一般会捕捉到所有异常



try:
    print a
except Exception as e:
    print "error:" + str(e)
else:   #如果没有引发异常会执行else
    print "else..."
finally: #无论是否异常都会执行finally
    print "finallly"



#raise语句用来抛出一个异常,参数必须为异常的实例或者Exception的子类

class MyError(Exception):
    def __init__(self,value):
        self.value = value
    def __str__(self):
        return self.value

#raise MyError("MyError...")



#assert语句用于检查条件表达式是否为真,不为真则触发异常,又称断言语句

assert 1==1
assert 1!=1 #触发
