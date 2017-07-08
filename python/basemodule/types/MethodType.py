#coding:utf-8
#动态增加成员方法
from types import MethodType

class A:
    def __init__(self):
        self.name = 'linwei'


def func(self):
    print(self.name)
a = A()
a.getName = MethodType(func,a)
a.getName()

