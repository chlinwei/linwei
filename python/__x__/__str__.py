#coding:utf-8
#__str__ :str()函数实际上返回的是__str__函数返回的结果
#print函数是先看有没有__repr__函数,在看有没有__str_函数
class Student(object):
    def __init__(self,name):
        self.name = name
    def __str__(self):
         return "Student object(name:%s)" % self.name

s = Student("linwei")
print(s)  #返回__str__的返回值
print(str(s)) #调用__str__
print(repr(s))

