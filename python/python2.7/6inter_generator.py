#_*_coding:utf-8 _*_

#可迭代对象(Iterable):只要实现了__iter__方法的对象就是可迭代的,
#__iter__方法会返回迭代器(iterator)本身

lst = [1,2,3]
print lst.__iter__() #<listiterator object at 0x7f24264d7210>

#判断一个对象是否是可迭代对象
from collections import Iterable
print isinstance('abc',Iterable) #True
print isinstance(1,Iterable) #False

#可迭代对象一般都用for循环遍历元素,也就是说能用for循环的对象都称为可迭代对象
lst = [1,2,3]
for i in lst:
    print i


#迭代器(Iterator),具有next方法的对象都是迭代器
#调用next方法,迭代器会返回它的一个值,如果next方法被
#调用又没有值可以返回,就引发一个StopInteration异常


#使用迭代器的好处
#1)如果使用列表,计算值时会一次获取所有的值,那么就会占用更多内存,而迭代器是一个接一个计算
#2)使代码更加通用,更简单


d = {'a':1,'b':2,'c':3}
iter_items = d.iteritems()
print iter_items.next()


#iter()函数,将可迭代对象转化为迭代器
lst = [1,2,3] #是一个可迭代对象,但是并不是迭代器,不具备next方法
iter_lst = iter(lst)
print iter_lst.next()

#itertools模块,内置的,提供可操作迭代对象的函数,可生成迭代器,也可以生成
#无限的序列迭代器
from itertools import *
counter = count(1,2) # 用法:count(start=0,step=1),返迭代器
print counter.next() #1
print counter.next() #3
print counter.next() #5


#cycle(iterable):生成迭代器
i =  cycle(['a','b','c'])
print i.next() #a
print i.next() #b


#repeat(object [,times]):生成迭代器,迭代器每次都返回object,times指定返回对象的次数
i = repeat(100,2)
print i.next()
print i.next()
#print i.next() #error

#islice(Iterable,[start,] stop [,step]),可设置起始位置,步长
i = islice([1,2,3,4,5,6,7,8,9],1,5,2)
print i.next() #2
print i.next() #4
#print i.next() #error

#chain(*iterables) ,可接受多个可迭代对象
l1 = [1,2,3]
l2 = [2,3,4]
i = chain(l1,l2)
print i.next() #1
print i.next() #2
print i.next() #3
print i.next() #2
print i.next() #3
print i.next() #4


#groupby(iterable[,keyfunc1])将可迭代对象中重复元素挑出来放到一个迭代器中
for key,group in groupby('abcddCca'):
    print key,list(group)

#   a ['a']
#   b ['b']
#   c ['c']
#   d ['d', 'd']
#   C ['C']
#   c ['c']
#   a ['a']

#groupby方法是区分大小写的,如果想把大小写的都放到一个迭代器中,
#可以定义函数处理:
for key,group in groupby('abacddCca',lambda c:c.upper()):
    print key,list(group)
#   A ['a']
#   B ['b']
#   C ['c']
#   D ['d', 'd']
#   C ['C', 'c']
#   A ['a']


#imap(func,*iterables):用于处理多个可迭代对象
a=  imap(lambda x,y :x *y,[1,2,3],[4,5,6])
print a.next()  #4
print a.next()  #10
print a.next()  #18


#ifilter(function or None,sequence):过滤序列
i = ifilter(lambda x:x%2==0,[1,2,3,4])
for i in i:
    print i
#当使用for语句遍历迭代器时，步骤大致这样的，先调用迭代器对象的__iter__方法获取迭代器对象，再调用对象的__next__()方法获取下一个元素。最后引发StopIteration异常结束循环


#生成器函数,和retuen差不多,只是yield是暂停函数,生成器主要是
#用来创建迭代器的
#yield value, value 是__next__调用者

def func():
    for i in range(5):
        yield i
g = func()  #func是生成器(也是个函数),g=func()即由生成器func生成迭代器g
print isinstance(g,Iterable) #True
for i in g:
    print i



#生成器表达式和推倒式表达式差不多,只是把[]改为()
result=(x for x in range(5))
print result  #<generator object <genexpr> at 0x7f78742b3870>

