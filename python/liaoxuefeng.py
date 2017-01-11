
#list(列表)

classmates = ['Michael','Bob','Tracy']
len(classmates) #返回序列中元素个数
min(classmates) #返回序列中最小的元素
min(1,2,3,'hello') #报错,字符串和int类型的元素无法作比较,max也一样
max(classmates) #返回序列中最大的元素
classmates[-1] #最后一个元素
classmates.append('Adam') #在末尾添加一个元素,返回None
classmates.append(1,'linwei') #再下表为1元素后面插入
classmates.pop()#删除最后一个元素,返回元素的值
classmates.pop(1)#删除下标为1的元素,不能指定不存在的下标(报错)

#count(value) 参数:序列中某个元素的值,返回值:这个值在序列中出现的次数
[1,1,1,2,3].count(1) #3
'11123'.count('1') #3

#extend(iterable)参数:一个可迭代对象,返回值:None,调用者改变了
a = [1,2,3,4]
b = ['hello','world']
a.extend() #a变为了[1,2,3,4,'hello','world]
c = 'haha'
b.extend(c) #b变为了['hello','world','h','a','h','a']

#迭代
list((1,2,3,4))#result:[1,2,3,4] #list函数(其实是个对象)的参数是可迭代对象,返回对应的列表


#iter(可迭代对象)函数内置,返回这个对象的迭代器
l = [1,2,3,4]
it = iter(l)
for i in it:
    print i #i的类型int即列表中对应项的类型

#判断一个对象是否是可迭代对象.
from collections import Iterable  
isinstance('abc',Iterable) #True


#enumerate
for i in enumerate(['A','B','C']):
    print type(i) #i为一个元组,包含两项目
for i,value in enumerate(['A','B','C']):
    print i,value
#result  0 A 1B 2C

for x,y in [(1,1),(2,4),(3,9)]:
    print x,y

#l.index(value,[start,[stop]]) 作用:返回序列中中第一个匹配value的索引.
#如果value在start(闭区间) 到stop(开区间)不存在,则报错ValueError
[1,2,3,'hello','hello'].index('hello')#3
[1,2,3,1,1,1].index(1,0,1) #result:0
[1,2,3,1,1,1].index(1,1,2) #result:ValueError


#l.insert(index.object):只是对list(列表)有作用,在索引index前插入object
a = [1,2,3,4,5]
a.insert(3,'four')#在a[3]前插入'four' #result: [1,2,3,'four',4,5]


#l.reverse:将列表中的元素顺序反转
x = [1,2,3]
x.reverse() #[3,2,1]


#reversed(object): object是序列,返回一个可迭代的对象

it = reversed('hello')
for i in it:
    print i  #'0','l','l','e','h'
#或者 print(next(a))



#序列相加
[1,2,3,4] + ['hello',34] #[1,2,3,4,'hello',34]
[1,2,3,4] + 'hello' #错误,左边是列表,右边是字符串
str.capitalize() #参数无,返回一个首字母大写,其他字母不变的副本

#成员资格in运算符:检查一个值是否在序列中
print 'h' in 'hello' #result:True

#序列相乘
'python' * 3 #result:'pythonpythonpython'
[1,2,3] * 3 #result:[1,2,3,1,2,3,1,2,3]
[None] * 3 #result:[None,None,None]

#赋值
a=[1,2,3]
a[0] = 33 #ok
a[3] = 45 #报错,赋值不能超过最大索引值

#删除
a = [1,2,3]
del a[0] #[2,3]
del a[0] #[3]
del a[0] #[]
del a #整个a就没有了,而不是为[]


#列表推倒式(列表生成式)
#Python的列表推导式(轻量级循环):是用其他列表创建新的表
#书写形式:[表达式 for 变量 in 列表]或者[表达式 for 变量 in 列表 if 条件]

print(x*x for x in range(10))#{0,1,4,16,25,36,49,64,81}

import os
[d for d in os.listdir(.)] #当前目录下的所有文件名


#for循环可以同时使用更多的变量
d = {'x':'A','y':'B','z':'C'}
[k + '=' + v for k,v in d.iteritems()] #result: ['y=B','x=A','z=C']

print([s.lower() for s in 'HELLO']) #result:['h','e','l','l','o']


#<------------------------------------------
#list或tuple分片(切片)


numbers=[1,2,3,4,5,6,7,8,9]
numbers[2:8:2]  #[3,5,7]
#step为正数由小到大排序
#起始值:numbers[2]=3
#最大值小于numbers[8]=9(即最大值小于9)

numbers[8:3:-2]  #[9,7,5]
#step为负数由大到小排序
#起始指(也为最大值):numbers[8]=9
#最小值大于numbers[3]=4(即最小值大于4)

numbers[-3:-1] #[7,8]
#step为正数由小到大排序
#最后一二元素的编号为-1
#起始值:numbers[-3]=7
#最大值小于numbers[-1]=9(即最大值小于9)
 
numbers[-3:0] #[]
#step为正数由小到大排序
numbers[-3]=7
numbers[0]=1
#由于是由小到大可以7并不是小于1的所以没有值

numbers[-3:] #[7,8,9]
#step为正数由小到大排序
#起始值:numbers[-3]=7
#不过右边最大值为空,则能包含结尾的最大元素

numbers[:]  #[1,2,3,4,5,6,7,8,9]
#step为正由小到大
#起始值为空就是最小元素numbers[0]=1
#最大指为空:表示可以取到最大值numbers[8]=9

numbers[1:100] #[1,2,3,4,5,6,7,8,9]这也是没问题的
#------------------------------------------>

#分片赋值(实际上是替换)

num = [1,2,3,4,5]
num[1:3]=['hello',34,43] #将num[1],num[2]替换为了'hello',34,43 ,其他不变
#result:[1,'hello',34,43',3,4,5]

num = [1,2,3,4,5]
num[1:3] = ['hello'] #讲num[1],num[2]替换成了'hello'
#result:[1,'hello',4,5]


#tuple(元组)
t = ()#定义一个空的元组,结果为()
t = (1)#结果为1但是最好这样写
t = (1,)#结果为(1,)
t = 1,2,3,4,5#也是一个元组

#dict(字典)
d = {'Michael':90,'Bob':45,'Tracy':85}
print 'Thomas' in d #False,in判断key是否存在
print(d.get('Thomas')) #返回None
print(d.get('Thomas',89))#返回89,但是d并不会增加元素
d.pop('Bob')#删除一个key,返回对应的value,对应的value也会删除


#iteritems()返回一个字典的可迭代对象
d = {'x':'A','y':'B','z':'C'} 
for k,v in d.iteritems():#字典的每一相是个元组
    print k,'=',v




#set
s = set([1,2,3,3,3]) #set的参数类型为list,result:set([1,2,3])
s.add(4) #添加一个key,返回None
s.remove(3) #删除key,参数为key,返回None,如果key不存在则报错

#help
help(abs) #调到abs的帮助文档

#cpm(a,b)比较大小,a>b返回1,a=b返回0,a<b返回-1
cmp(1,2) #-1


#数据类型转换
a = '123'
print(type(int('123'))) #<type 'int'>
print(type(a)) #<type 'str'>



#空函数
def func():  #如果定义一个函数什么都不做,用pass语句,如果不写pass语句则报错
    pass 
#参数检查:调用函数时,如果参数个数不对,则抛出TypeError
#函数可以返回多个值,其实就是返回一个元组


def power(x,n=2) #n为默认参数

#<------------------------------------------
#可变参数,允许你传入任意的参数个数
def cal(*numbers): #numbers前面加*表示可变参数
    sum =0
    for n in numbers
        sum = sum+n
    return sum

cal(1,2,3) #6
#如果有个变量t为list或者元组
nums = [1,2,3]
cal(nums) #则报错,因为参数是可变参数,只接受1,2,3这样的形式传入
cal(*nums) #加了个*号,就表示不再以[1,2,3]传入了,而是以1,2,3传入
#------------------------------------------>



#<------------------------------------------
#关键字参数,允许你传入任意的参数个数
def person(name,age,**kw): #kw前面加上**表示关键字参数
    print 'name:',name,'age:',age,'other:',kw


person('Bob',35,city='Beijing')#注意:city不能加引号(报错)
#result: name Bob age: 35 other: {'city': 'Beijing'}

#如果存在一个变量为字典
kw = {'city':'Beijing','job':'Engineer'}
person('jack',24,**kw) #与上述可变参数类似 

kw = {'name':'linwei','job':'Engineer'} #报错,name与def perso中的参数name相同了.
#------------------------------------------>




#<------------------------------------------
#参数组合
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
#------------------------------------------>




#生成器(Generator)
#创建一个生成器有两种方法,生成器就是个迭代器
#方法1.和列表推到式很像,只是把[]改为()了
#列表推到式:[x*x for x in range(1,100)]
#生成器:(x*x for x in range(1,100))

for it in (x*x for x in range(1,100)):
    print i

#或者
#print(g.next()) ...,如果没有更多的元素了,就抛出StopIteration

#方法2:
def odd(): #注意odd是个函数,odd()是生成器(迭代器),即返回的是生成器
    print 'step1'
    yield
    print 'step2'
    yield
    print 'step3'
    yield
    print 'step4'

for i in odd():
    pass
#理解:一般函数遇到return或者执行到最后一行语句就返回
#而生成器函数,在每次调用后,遇到yield语句返回,再次执行时从上次返回的yield语句继续执行


#map函数map(函数,序列) 
#作用:将传入的函数一次作用到序列的每个元素
#并把结果作为新的list返回

print(map(lambda x:x*x,[1,2,3,4,5,6])) #map函数,返回一个列表
print [x*x for x in [1,2,3,4,5,6]] #列表推倒式,返回一个列表
print (x*x for x in [1,2,3,4,5,6]) #生成器(迭代器),返回一个生成器


#reduce(函数,列表)
#作用:把一个函数作用于一个序列上,reduce
#把结果继续和序列写下一个元素做累积计算


def add(x,y):
    return x + y
reduce(add,[1,2,3,4,5]) #返回15


#filter(函数,序列),返回对应的序列
#作用:过滤功能,filter()把传入的函数依次
#作用于每个元素,根据函数返回值进行判断
#如果返回True,则保留该元素,否则移除该元素

def  is_odd(n):
    return n % 2 == 1
filter(is_odd,[1,2,3,4,5]) #[1,3,5]


#sorted(iterable, cmp=None, key=None, reverse=False),内置,返回list

sorted([3,1,2,34,-1,0]) #默认是有小到大排序
def reversed_cmp(x,y):
    if x > y:
        return -1
    if x < y:
        return 1
    return 0
print(sorted([3,1,2,34,-1,0],reversed_cmp))  #由大到小

#闭包:函数作为返回值
def lazy_sum(*args):
    def sum():
        ax = 0
        for n in args:
            ax =ax + n
        return ax
    return sum

f = lazy_sum(1,2,3,4,5,6)
print(f())



#匿名函数:关键字lambda表示匿名函数
#好处:不必担心与其他函数名冲突
print(map(lambda x: x*x,[1,2,3,4,5]))
#lambda x:x*x相当于
def f(x):
    return x*x 


#装饰器(Decorator)
#作用:代码在运行时,动态增加的方式,称之为"装饰器"


def log(func):
    def wrapper(*args,**kw):
        print 'call %s:' % func.__name__
        return func(*args,**kw)
    return wrapper

@log
def now():             # => now = log(now),此时now是wrapper函数
    print '2013-12-25'

print(now.__name__) #wrapper


import functools
def log(func):
    @functools.wraps(func)
    def wrapper(*args,**kw):
        print 'call %s:' % func.__name__
        return func(*args,**kw)
    return wrapper

@log
def now():             # => now = log(now)
    print '2013-12-25'


print(now.__name__) #now



#偏函数:将一个函数的某些参数给固定住,(也就是设置默认值)返回新的函数
import functools
int2 = functools.partial(int,base=2)
print(int2('10010001'))
