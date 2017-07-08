#coding:utf-8
#判断一个实例对象是否是某个类型(即由谁实例化)或者是否继承于某个类(即实例对象的原型)

from collections import Iterable

class Person:
    pass

p1 = Person()
print(isinstance(p1,Person)) #True,类型
print(isinstance(p1,object)) #True,原型
