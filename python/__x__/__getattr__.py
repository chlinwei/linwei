#coding:utf-8
#当如果调用不存在的属性时,会调用__getattr__
class Student(object):
    def __init__(self):
        self.name = 'linwei'
    def __getattr__(self,attr):
        if attr == 'score':
            return 80

s = Student()
print(s.score)
