#__slots__:限制成员属性,不论是直接在类里添加属性,还是动态添加属性都受到限制

class A:
    __slots__ = ("name")
    def __init__(self):
        self.name = 'linwei'
        #self.age = 24 报错

a = A()
a.name
#a.x = 100  报错






