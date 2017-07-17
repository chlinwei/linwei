#super(类名,实例).继承类的方法或属性
class Animal(object):
    def __init__(self,name):
        self.name = name
    def greet(self):
        print("Hello,I am %s." % self.name)

class Dog(Animal):
    def greet(self):
        super(Dog,self).greet()
        #Animal.greet(self)
        print("wangwang")

d = Dog('dog')
d.greet()
