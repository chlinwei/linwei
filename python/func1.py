#_*_ coding:utf-8 _*_
#1.__call__()方法
#所有的函数都被称作可对象,此方法将一个对象变成一个可调用的对象
#相当于重载了括号运算符
class Person:
    def __init__(self,name):
        self.name = name
    def __call__(self,friend):
        print 'my name is :%s',self.name
        print 'my friend is :%s',self.friend

p = Person('xiaoming')
p('xiaohua') #这里把p这个对象当做函数了,传入参数调用__call__函数



#2.__str__()函数,返回一个对象的字符串信息
class Friend():
#    def __str__(self):
#        return 'hahah'
    pass
print Friend() #如果不重写__str__()函数,则Friend()里的默认的__str__()
#函数返回<__main__.Friend instance at 0x7f5653426290>,如果重写,则返回haha


#3.getattr(object,name,default),如果没有name这个属性或方法,
#返回default,default可以为属性或者方法
class A:
    def __init__(self):
        self.name = 'xiaoming'
    def method(self):
        print 'method...'

c = A()
print getattr(c,'name','not find name!') #xiaoming
print getattr(c,'nameaa','not find name!') #not find name!



