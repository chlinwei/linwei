#coding:utf-8
#一般调用成员函数instance.方法,但我们如果要直接调用实例本身的方法instance(),则要实现
#__call__方法
class Student(object):
    def __init__(self):
        self.name = 'linwei'
    def __call__(self):
        print("My name is %s" % self.name)

s = Student()
s()

