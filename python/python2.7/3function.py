#_*_ coding:utf-8 _*_
#def functionName(parms1,parms2,...):
#    code block
#    return expression

######### 参数组合 ########
def func(a,b,c=0,*args,**kw):
    print 'a=',a,'b=',b,'c=',c,'args=',args,'kw=',kw

#参数的顺序必须是:必选参数,默认参数,可变参数,关键字参数 
func(1,2) #ok,result:a=1 b=2 c=0 args=() kw={}
func(1,2,c=3) #ok,result:a=1 b=2 c=3 args=() kw={}
func(1,2,3,'a','b')#ok,result:a=1 b=2 c=3,args=('a','b') kw={}
func(1,2,3,'a','b',x=99)#ok,result:a=1 b=2 c=3,args=('a','b') kw={'x':99}
args = (1,2,3,4)
kw = {'x':99}
func(*args,**kw)#这样也OK,result: a = 1 b = 2 c = 3 args = (4,) kw = {'x': 99}}



######### 嵌套函数 ########
#内层函数可以访问外层函数的作用域,但是不能修改
#外层函数作用域里的变量

def func(a):
    def func2(b):
        return a*b
    return func2

f = func(2)
print f(3) #6


def func():
    x = 2
    def func2():
        x=5 #注意这里x是func2作用域里的5
    func2()
    return x

#print func() #2



def func():
    x = 2
    def func2():
        x += 1 #这里引用的是外层func作用域的变量,不能修改
    func2()
    return x

#func() ,error



######### 闭包 ########
#指的是一个拥有许多变量和绑定了这些变量的环境表达式(通常是一个函数)
#,因而也是该表达式的一部分

def func(a):
    def func2(b):
        return a * b
    return func2

f = func(2)
f(5) #10
 



######### 高阶函数 ########
#满足高阶函数的条件:
#1)能接受一个或多个函数作为输入
#2)输出一个函数

def f(x):
    return x*x

def f2(func,y):
    return func(y) 

print f2(f,2) #这里f2就是个高阶函数



######### 函数装饰器(decorator) ########
#本身是一个函数,包装另一个函数或类,他可以让其他函数
#在不需要改动源代码的情况下动态增加功能,装饰器返回的是函数

def deco(func):
    def f(a,b):
        print "%s parameter:%d %d " %(func.__name__,a,b)
        return func(a,b)
    return f
@deco  #相当于 f1=deco(f1)
def f1(a,b):
    print "f1 result:" + str(a * b)

f1(1,2) 
#f1 parameter:1 2 
#f1 result:2



###装饰器加参数
def log(arg):
    def deco(func):
        def _deco(*args,**kwargs):
            print "%s - function name:%s" %(arg,func.__name__)
            return func(*args,**kwargs)
        return _deco
    return deco

@log("info")  #先调用log("info")函数返回的deco作为函数装饰器
def f1(a,b):
    print "f1() run."
    print a + b

f1(1,2)
#info - function name:f1
#f1() run.
#3



######### 匿名函数 ########
#lambda函数一行就写一个函数，省去了定义函数过程,让
#代码更加精简

f = lambda a,b:a*b #冒号左边是参数,右边是返回值
print f(2,3) 



######## 内置高级函数 ####

#map(函数,序列 )
lst=[1,2,3,4,5,6]
print map(lambda x : str(x) + ".txt",lst) 

#filter(函数,序列),根据函数返回值真假
lst = [1,2,3,4,5]
filter(lambda x:x%2 == 0,lst)




