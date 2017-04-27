#_*_coding:utf-8 _*_
#面向对象涉及到: 
#继承
#动态绑定:在不修改源代码的情况下,动态绑定方法来给实例增加功能
#封装
#多态性
#消息传递:一个对象调用另一个对象的方法
#方法


####### 成员函数 #########
#一.成员函数的第一个参数为实例化对象
#二.调用成员函数的方式有两种:
#1. 实例化对象.成员函数,这里实例化对象自动当作参数传入到函数中
#2. 类名.成员函数(实例化对象)
#三.成员函数由实例化对象拥有,多个实例化对象不共享同一个成员函数


class A:
    def func1(self):
        print type(self)
    def func2(self):
        self.func1() #调用成员函数的第1种方法
        A.func1(self)  #调用成员函数的第2种方法

a = A()
b = A()
a.func1() #调用成员函数的第1种方法
A.func1(a) #调用成员函数的第2种方法
print a.func1 #<bound method A.func1 of <__main__.A instance at 0x7fa558a872d8>>
print b.func1 #<bound method A.func1 of <__main__.A instance at 0x7fda2d479320>>
#实例对象不共享成员函数




####### 静态函数 #########
#一.静态函数不像成员函数第一个参数为实例化对象,静态函数没有这个特点
#使用静态函数的好处是,不需要实例化就能使用这个方法.
#二.调用方法
#1. 类名.静态函数
#2. 实例化对象.静态函数
#三.静态函数只实例化一次,被类对象,类实例化对象共享,类似c++中的虚继承

class B:
    @staticmethod
    def func(): #区别一
        print "hello,world"

b1 = B() #调用方法2
b2 = B() 
#区别二
print B.func #<function func at 0x7f5e16313938> #调用方法1
print b1.func #<function func at 0x7f5e16313938> 
print b2.func #<function func at 0x7f5e16313938>




####### 类函数 #########
#一.第一个参数传入的是类对象而不是实例对象
#二.调用方法
#1.类名.类函数
#2.实例化对象.类函数
#三.类，实例化对象之间共享一个类函数

#类函数
class C:
    day=0
    month=0
    year=0
    def __init__(self,year=0,month=0,day=0):
        self.day = day
        self.month = month
        self.year = year

    @classmethod
    def get_date(cls,data_string):
        year,month,day=map(int,data_string.split('-'))
        date1 = cls(year,month,day)
        return date1
    @classmethod
    def func(cls):
        print "ok"
    def out_date(self):
        print "year:"
        print self.year
        print "month:"
        print self.month
        print "day:"
        print self.day



r = C.get_date("2016-8-6")
r.out_date()
c1 = C()
c2 = C()
c1.func() #ok #第二种调用方法
c2.func() #ok
C.func() #ok #第一种调用方法
print c1.func #<bound method classobj.func of <class __main__.C at 0x7f0a6f7f06d0>> 
print c2.func #<bound method classobj.func of <class __main__.C at 0x7f0a6f7f06d0>> 
print C.func #<bound method classobj.func of <class __main__.C at 0x7f0a6f7f06d0>> 
#类对象,实例化对象之间共享类函数

#这个例子技巧:你以后重构类的时候就不必修改构造函数,先通过类调用类方法






####### 类变量 #########

class A:
    x = 100 #x被称为类变量

#
#            A
#          / |  \
#         a  a1 a2
# A在实例化对象的时候,会将A里的类变量赋值一份到实例对象中
# ,于是乎A类中含有类变量,a等实例对象中含有赋值过来的成员变量
# a.x代表的是a中的成员变量 ,A.x代表的是类变量,改变a.x这样的成员
#变量不会对A中的类变量,和其他实例对象中的成员变量x造成影响,
#改变类变量x,会对没有没有改变x的实例对象造成影响和类变量x一致,
#但是不会对已经改变x的实例对象造成影响

a = A()
a1 = A()

a.x = 200
print A.x #100  #对类变量和其他实例对象中的x不会造成影响
print a1.x #100

A.x = 300
print a.x #200 已经改变过的实例
print a1.x #300  没有改变过的实例


#单下划线开始的变量和函数有两个特点:
#1)模块里单下划线开始的变量和函数在另一个py文件里不能用from module import *导入,但是可以import module 导入或者 from module import 具体变量或者函数,这样可以导入
#如:
#vi hello.py
#_name =  'xiaoming'
#def _func():
#	print 'hello,world'
#
#vi main.py
#
#from hello import *
#print _name #error
#_func() #error
#
#2)在类的内部以单下划线开始的变量或者函数,表示警告你这个变量或者函数
#虽然可以被访问,但请把他们视为私有的


