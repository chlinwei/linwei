#_*_ coding:utf-8 _*_
#python中内建的数据结构有列表(list),元组(tuple),字典(dict),集合(set)
#序列包含列表和元组

######## 列表(list) ###########

lst = ['a','b','c',1,2,3]

#基本操作
#追加一个元素
lst.append(4)  #无返回值,lst =>['a','b','c',1,2,3,4] 
#统计列表中a出现的字数
print lst.count('a') #1

#将以恶搞列表作为元素添加到lst列表中
a = [5,6]
lst.extend(a) #无返回值lst =>['a', 'b', 'c', 1, 2, 3, 4, 5, 6]

#查找元素索引位置
print lst.index(1) #3

#在下标为3的元素前插入一个元素0
lst.insert(3,0) #['a', 'b', 'c', 0, 1, 2, 3, 4, 5, 6]

#删除最后一个元素
lst.pop() #lst =>['a', 'b', 'c', 0, 1, 2, 3, 4, 5, 6]
#删除下标为3的元素
lst.pop(3) #['a', 'b', 'c', 1, 2, 3, 4, 5]

#删除元素为a
lst.remove('a') #无返回值,lst=['b', 'c', 1, 2, 3, 4, 5]>
#倒序排列元素
lst.reverse() #无返回值,lst = >[5, 4, 3, 2, 1, 'c', 'b'] 

#正向排序元素
lst.sort()  #[1, 2, 3, 4, 5, 'b', 'c']

#列表相连
a = [1,2,3]
b = ['a','b','c']
print a + b #[1, 2, 3, 'a', 'b', 'c']

#列表*整数
print a*2  #[1, 2, 3, 1, 2, 3]



#相关迭代器生成函数
lst = ['a','b','c',1,2,3,4,5]
it = reversed(lst) #返回一个迭代器,同理sorted
for i in it:
    print i


#切片

lst = [1,2,3,4,'a','b','c'] 
#返回第一个元素
print lst[0] #1,lst不变
#返回倒数第一个元素,lst不变
print lst[-1] #c
#取出倒数第一个元素,lst不变
print lst[0:-1] #[1,2,3,4,'a','b']
#返回第一个至第四个元素
print lst[0:4] #[1,2,3,4]

#情况列表
lst = [1,2,3,4,'a','b','c']
#方法1
lst = []
#方法2
lst = [1,2,3,4,'a','b','c']
del lst[:]
print lst  #[]

#删除列表
lst = [1,2,3,4,'a','b','c']
del lst
#print lst ,error

#del语句 ,可以删除一个下标范围的元素
lst = [1,2,3,4,'a','b','c']
del lst[0:4]
print lst #['a','b','c']


#列表推到式
lst = []
lst = [i for i in range(5)]
print lst #[0,1,2,3,4]


#遍历列表
lst = ['a','b','c',1,2,3]
for i in range(len(lst)):
    print i,lst[i]
#0 a
#1 b
#2 c
#3 1
#4 2
#5 3


for index,value in enumerate(lst):
    print index,value
#0 a
#1 b
#2 c
#3 1
#4 2
#5 3




######## 元组(tuple) ###########
#元组和列表不同之处在于元组的元素不可修改


######## 集合(set) ###########
#集合是一个无序不重复的元素的序列,主要功能用于删除重复元素和关系测试
#集合对象还支持联合(union),交集(intersection),
#差集(difference)和对称差集(sysmmetric difference)数学运算

#创建空集合
s = set() #set([])

#添加元素
s.add('a') 
#update将传入的字符串拆分成单个传入到集合中和set('1234')一样
s.update('1234') #set(['a', '1', '3', '2', '4'])

#删除元素
s.remove('4') #没有'4'这个元素会报错
#删除元素,和remove差不多,这个如果没有元素'4'不会报错
s.discard('4') 
#删除第一个元素
s.pop()
#清空元素
s.clear() #s([])

#列表转集合
lst = ['a','b','c',1,2,3,1,2,3]
s = set(lst) #set(['a', 1, 'c', 'b', 2, 3])

#关系测试

#符号   描述
#-      差集
#&      交集
#|      并集
#!=     不等于
#==     等于
#in     是成员为真
#not int 不是成员为真

a = set([1,2,3,4,5,6])
b = set([4,5,6,7,8,9])
#返回差集,a中有的b中没有的
a - b #set[1,2,3]
#返回交集
a & b #set[4,5,6]
#返回合集
print a|b #[1,2,3,4,5,6,7,8,9]




######## 字典(dict) ###########
#字典以关键字为索引,关键字可以是任意不可变对象

d = {'a':1,'b':2,'c':3}
#返回所有的键值,顺序是乱的
print d.items() #[('a', 1), ('c', 3), ('b', 2)]
#返回所有的键,顺序是乱的
d.keys()  #['a','b','c']
#查看所有的值,顺序是乱的
print d.values() #[1,2,3]
#添加键
d['e'] = 4
#获取单个键的值,如果这个键不存在就会报错KeyError
#d['f'] error
#获取单个键的值,如果有这个键就返回对应的值,否则就返回自定义的值
d.get('a','no')

print d #{'a': 1, 'c': 3, 'b': 2, 'e': 4}
#删除第一个键值
print d.popitem() #返回('a',1),元组
print d #{'c': 3, 'b': 2, 'e': 4}

#删除指定键
print d.pop('c') #返回'c'键对应的值3
print d #{'b': 2, 'e': 4}
d2 = {'a':1}
d.update(d2) #无返回值d = >{'a': 1, 'b': 2, 'e': 4} 
#拷贝一个新的字典
dd = d.copy()  #dd和d都是独立的
#判断键是否在字典
d.has_key('a')
   
#可迭代对象

#d.iteritems() 获取所有的键值,很常用
#d.iterkeys() 获取所有的键
#d.itervalues() 获取所有的值

for i in d.iteritems():
    print i
#('a', 1)
#('b', 2)
#('e', 4)


for k,v in d.iteritems():
    print "%s:%s" %(k,v)
#a:1
#b:2
#e:4


#一个键多个值
#嵌入列表
d = {'a':[1,2,3],'b':2,'c':3}
#嵌入元祖
d = {'a':(1,2,3),'b':2,'c':3}
#嵌入字典
d = {'a':{'d':4,'e':5},'b':2,'c':3}



#collections 模块
#namedtuple和tuple差不多,但是tuple的下标只能是数字,
#namedtuple可以为任意

from collections import namedtuple
nt = namedtuple('point',['a','b','c']) #定义三个下标配
p = nt(1,2,3)  #给这三个下标赋值  p=> point(a=1, b=2, c=3)
print p.a #1
print p.b #2
print p.c #3


#deque双向列表:由于list数据量大时,插入和删除元素很慢,
#deque的作用就是为了快速实现插入和删除元素的双向列表

from collections import deque
q = deque(['a','b','c'])
q.append('d') 
print q  #deque(['a', 'b', 'c', 'd']))
q.appendleft(0) #deque([0, 'a', 'b', 'c', 'd'])
q.pop() #返回值'd'
q.popleft() #返回0



#Counter计数器

from collections import Counter
c = Counter()
for i in "hello,world":
    c[i] += 1

print c
#Counter({'l': 3, 'o': 2, 'e': 1, 'd': 1, 'h': 1, ',': 1, 'r': 1, 'w': 1})

#OrderedDict:内置的dict是无序的,OrderedDict函数功能就是生成有序的字典
d = {'a':1,'b':2,'c':3}
print d #{'a': 1, 'c': 3, 'b': 2}

from collections import OrderedDict
od = OrderedDict()
od['a'] = 1 
od['b'] = 2
od['c'] = 3
print od #OrderedDict([('a', 1), ('b', 2), ('c', 3)])

#通过json模块转为字典
import json
print json.dumps(od) #'{"a": 1, "b": 2, "c": 3}'


#常见的数据类型转换
#字符串转整数
i='111'
int(i) #111

i='111abc' 
#int(i) ,error

#整数转字符串
i = 100
str(i)  #'100'

#字符串转列表
s = 'abc'
print list(s) #返回列表,['a','b','c'],s不变

#列表转元组
lst = ['a','b','c']
tuple(lst) #('a','b','c')

#元组转列表
t = (1,2,3)
list(t) #[1,2,3]

#字典格式的字符串转字典
#方法1:eval
s = '{"a":1,"b":2,"c":3}'
eval(s) #返回{'a': 1, 'c': 3, 'b': 2},s还是str
#方法2:json
s = '{"a":1,"b":2,"c":3}'
print json.loads(s) #{u'a': 1, u'c': 3, u'b': 2}



#两个内建函数
#join
s = "ttt"
print "+".join(s) #返回 t+t+t ,s不变

#eval():将参数字符串当成Python表达式来处理

print eval('1+1') #2
